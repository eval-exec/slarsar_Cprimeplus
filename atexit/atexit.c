#include <stdio.h>
#include <stdlib.h>

void func1(){
	printf("exit at 1\n");
}
void func2(){
	printf("exit at 2\n");

}

typedef struct {
	int a;
	int b;
}A;


int main(){
	A ff;
	

	printf("a1");
	atexit(func1);
	atexit(func2);
	exit(0);
}

