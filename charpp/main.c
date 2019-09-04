#include <stdio.h>

int main() {
    char * array[10];
    int i = 0;
    for (i  = 0 ; i < 10; i++ ){
        char x[] = "jackkkkffffffffffffffffffff";
        array[i] = x;
        printf("address of array[%d]is %p\n",i,&array[i]);
        printf("size of %ld\n", sizeof(char));
    }

    printf("array is %s",array[0]);
    return 0;
}