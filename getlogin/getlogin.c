#include <stdio.h>
#include <unistd.h>

int main() {
char * loginname;
loginname = getlogin();
printf("loig in name is %s\n",loginname);
return 0;
}
