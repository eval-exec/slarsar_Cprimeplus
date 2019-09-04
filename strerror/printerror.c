#include "stdio.h"
#include "string.h"

void main()
{
	int i;
	for (i = 0; i < 300; i++) 
	{
		char * errStr;
		errStr = strerror(i);
		printf("i is %d, error is %s\n",i,errStr);

	}	
}
