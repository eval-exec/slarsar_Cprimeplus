#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {

    char *ball = "b";
    int pipes_ptoc[2];
    if (pipe(pipes_ptoc) < 0 ) {
        perror("pip init error :");
    }
    int pipes_ctop[2];
    if (pipe(pipes_ctop) < 0 ) {
        perror("pip init error :");
    }
    char * child_buf;
    child_buf = malloc(1);
    char * parent_buf;
    int start = 0;
    parent_buf = malloc(1);

    int forked_pid = fork();
    if (forked_pid == 0) {
        for (;;) {

            if (start == 0) {
                printf("start is 0\n");
                if (write(pipes_ctop[1], ball, 1) < 0 ) {
                    perror("child write error :");
                }
                printf("child process write %s\n", ball);
                start = 1;
                printf("child continue\n");
                continue;
            }
            printf("start is %d\n",start);

            printf("child read now");
            if (read(pipes_ptoc[0], child_buf, 1) < 0 ) {
                printf("error read in child \n ");
                break;
            }
            printf("child process get %s\n", child_buf);
            write(pipes_ctop[1], child_buf, 1);
            printf("child process write %s\n", child_buf);
        }

    } else if (forked_pid > 0) {
        for (;;) {

            if (read(pipes_ctop[0], parent_buf, 1) < 0) {
                perror("parent read error :");
                break;
            }
            printf("parent process get %s\n", parent_buf);

            write(pipes_ptoc[1], child_buf, 1);
            printf("parent process write %s\n", ball);

        }

    } else {
        printf("fork error\n");
    }



}