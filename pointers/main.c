#include <stdio.h>
#include "stdlib.h"

int main(int argc, char **argv) {
    while (*++argv != NULL) {
        printf("%s\n",*argv);
    }
    printf("argc is %d\n",argc);
    return EXIT_SUCCESS;
}

