#include "stdio.h"

int main()
{
	
	int i[10];
	int *p = &i[0];
	int offset;
	offset = 1;
	printf("%p is origin p\n",p);
	p += offset;
	printf("%p is p += offset\n",p);

	p += 1;

	printf("%p is += 3 \n",p);
	return 0;
}
