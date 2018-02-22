/*
 ============================================================================
 Name        : 08_01.c
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
	void justRight(void);

int main(void) {
int n=getnumber();

if(n<50)
	tooSmall();

if((n > 50) && (n < 80))
	justRight();

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

void justRight(void) {
	printf("just right");
}
