#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"


void openParent(int *parent) {
	int one = 1;
	write(parent[1], &one, sizeof(int));

}

void closeParent(int *parent) {
	int one = 0;
	printf("closeParent send\n");
	write(parent[1], &one, sizeof(int));

}

void endParent(int *parent) {
	int one = 2;
	write(parent[1], &one, sizeof(int));
}

void filter(int *origin_pip, int *parentSignal, int prime) {

	int outPip[2];
	pipe(outPip);

	printf("origin_pip[0],is %d, origin_pip[1] is %d \n", origin_pip[0], origin_pip[1]);
	int out;

	printf("closed parentSignal\n");
	closeParent(parentSignal);
	for (; read(origin_pip[0], &out, sizeof(int)) >= 0;) {
		if (out % prime != 0) {
			if (write(outPip[1], &out, sizeof(int)) <= 0) {
				printf("write %d to out error \n");
			}
		}
	}

	printf("ready to write to origin pip\n");

	openParent(parentSignal);
	for (; read(outPip[0], &out, sizeof(int)) > 0;) {
		if (out == 0) {
			break;
		}
		printf("filter write %d to origin pipe\n", out);
		write(origin_pip[1], &out, sizeof(int));
	}

}


int main() {

	int start = 2;
	int end = 35;

	int p1[2];


	int parentSignal[2];
	pipe(parentSignal);

	if (pipe(p1) < 0) {
		printf("error create pipe\n");
		exit();
	}

	int pid;
	pid = fork();
	printf("p1[0],is %d, p1[1] is %d \n", p1[0], p1[1]);

	if (pid > 0) {
		printf("parent pid is %d\n", pid);
		for (int i = start; i <= end; i++) {
			if (write(p1[1], &i, sizeof(int)) <= 0) {
				printf("parent generate number error\n");
				exit();
			}
		}
		int signal;
		for (; read(parentSignal[0], &signal, sizeof(int));) {
			if (signal == 1) {
				int o = open((const char *) &p1[1], O_WRONLY);
				printf("parent get open p1 signal, result is %d\n", o);
			} else if (signal == 0) {
				printf("parent get close p1 signal, signal is %d\n", signal);
				close(p1[1]);
				printf("parent get close p1 signal, signal closed \n");
			} else if (signal == 2) {
				break;
			}
		}

		printf("parent waiting\n");
		wait();

	} else if (pid == 0) {

		printf("child:\n");
		int prime;

		int childR;
		for (; (childR = read(p1[0], &prime, sizeof(int))) > 0;) {
			printf("in child loop , prime is %d\n", prime);
			filter(p1, parentSignal, prime);
			printf("child R finished \n");
		}
		endParent(parentSignal);
		printf("child R is %d, exiting\n", childR);

		exit();
	} else {
		printf("fork error\n");
	}
	return 0;
}


