#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main() {

    char * ball ;
    int  forked_pid = fork();
    int pipes[2];
    pipe(pipes);
    char *child_buf;
    child_buf = malloc(1);
    child_buf = NULL;
    char * parent_buf;
    parent_buf = malloc(1);
    parent_buf = NULL;
    for (;;) {
        if (forked_pid  == 0 ) {

            read(pipes[0],child_buf,1);
            printf("child process get %s",child_buf);
            write(pipes[0],child_buf,1);
            printf("child process write %s",child_buf);

        }else if ( forked_pid > 0 ) {
            write(pipes[1],parent_buf,1);
            printf("parent process write %s",parent_buf);
            read(pipes[1],parent_buf,1);
            printf("parent process get %s",parent_buf);

        }else {
            printf("fork error\n");
            break;
        }

    }



}