#include "stdio.h"

int main()
{

	typedef struct {
		int arms;
		int legs;
		int hands;
	}BODY;

	typedef struct{
		int age;
		int hight;
		char* name;
		BODY* body;

	}HUMAN ;


	HUMAN I;
	I.age = 11;
	I.hight = 122;
	
	char n[] = "killers";
	I.name = n;
	BODY b;
	b.arms = 2;
	b.legs = 2;
	b.hands = 2;
	I.body = &b;
	printf("human name is %s\n",I.name);

	printf("human's age is %d\n",I.age);
}
