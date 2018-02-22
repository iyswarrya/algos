/*
 ============================================================================
 Name        : 08_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getnumber(void);
	void tooSmall(void);
	void tooLarge(void);
	void justRight(void);
	void checkError(int n);

int main(void) {
int n=getnumber();

/*if(n<50)
	tooSmall();*/

if((n > 50) && (n < 80))
	justRight();
else checkError(n);

	return EXIT_SUCCESS;
}

int getnumber(void){
	int n;
	printf("enter the number");
	scanf("%d",&n);
	return n;
}

void tooSmall(void) {
	printf("too small\n");
}

void tooLarge(void) {
	printf("too large\n");
}
void justRight(void) {
	printf("just right\n");
}

void checkError(int n){
	printf("check the number\n");
	if (n<50)
		tooSmall();
	else tooLarge();
}
