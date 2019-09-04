#include "stdio.h"
#include "stdlib.h"
int main(){
	int* p;
	p = malloc(100 * sizeof(int));
	if ( p == NULL ){
		printf("'out of memory \n'");
		exit(1);
	}else{
	printf("address of p is %p\n",p);
	printf("address of p's address is %p\n",&p);
	printf("value of p is %s\n",*p);
	}
}
