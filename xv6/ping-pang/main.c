#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void main() {

    char *ball = "b";
    int pipes_ptoc[2];
    if (pipe(pipes_ptoc) < 0) {
        perror("pip init error :");
    }
    int pipes_ctop[2];
    if (pipe(pipes_ctop) < 0) {
        perror("pip init error :");
    }
    char *child_buf;
    child_buf = malloc(1);
    char *parent_buf;
    int start = 0;
    parent_buf = malloc(1);

    int forked_pid = fork();
    int i;
    if (forked_pid == 0) {
        for (;;) {

            if (start == 0) {
                if (write(pipes_ctop[1], ball, 1) < 0) {
                    perror("child write error :");
                }
                start = 1;
                continue;
            }

            if (read(pipes_ptoc[0], child_buf, 1) < 0) {
                printf("error read in child \n ");
                break;
            }
            printf("child process get %s\n", child_buf);
            write(pipes_ctop[1], child_buf, 1);
            printf("child process write %s\n", child_buf);
        }

    } else if (forked_pid > 0) {
        clock_t t;
        t = clock();
        ulong PINGS = 100000;
        for (i = PINGS; i > 0; i--) {
            if (read(pipes_ctop[0], parent_buf, 1) < 0) {
                perror("parent read error :");
                break;
            }
            printf("parent %d process get %s\n", i, parent_buf);

            write(pipes_ptoc[1], parent_buf, 1);
            printf("parent %d process write %s\n", i,ball);

        }
        t = clock() - t;
        double time_token = (double) t / CLOCKS_PER_SEC;
        printf("time token = %f\n", time_token);
        printf("benchmakr score is %f persecond\n",PINGS/time_token);
        exit(0);

    } else {
        printf("fork error\n");
    }
    printf("exited");
}