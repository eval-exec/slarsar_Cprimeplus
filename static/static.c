#include "stdio.h"

int 
func(void)
{
static int counter = 1;
	int ret;
	++counter;
	ret = counter;
	printf("ret is %d \n",ret);
	return ret;
}

int 
main()
{
	int answer;
	answer = func() -func() * func();
	printf("%d is answer\n",answer);
}
