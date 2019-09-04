#include <stdio.h>

int main() {
    char * array[10];
    int i = 0;
    for (i  = 0 ; i < 10; i++ ){
        char x[] = "jackkkkffffffffffffffffffff";
        array[i] = x;
    }
    char **ptr = array;
    printf("address of ptr %p\n",ptr);
    ptr++;

    printf("ptr is %p\n",ptr);


    printf("array[0] is %p\n",&array[0]);
    printf("array[1] is %p\n",&array[1]);
    return 0;
}