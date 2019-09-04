#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	perror("nothingA");
	FILE * file1;
	file1 = fopen("data","r");
	if (file1 == NULL) {
		perror("data");
		return EXIT_FAILURE;
	}
	return 0;
}
