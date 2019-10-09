#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 2;
	printf("a's address is %p\n",&a);
	int *b = &a;

	printf("b is %d\n",*b);
	printf("b's address is %p\n",b);



}
