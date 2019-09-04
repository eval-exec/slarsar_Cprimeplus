#include "stdio.h"

int main()
{

	typedef struct {
	char a;
	int b;
	char c;
	}ALIG;
	ALIG x;
	printf("sizeof ALIG is %d",sizeof(ALIG));
	printf("pointer %p\n",&x);
}
