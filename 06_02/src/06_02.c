/*
 ============================================================================
 Name        : 06_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x=3;
	int y=7;

	printf("x==y: %d\n",(x==y));
	printf("x!=y: %d\n",(x!=y));
	printf("x>y : %d\n",(x>y));
	printf("x<y : %d\n",(x<y));
	printf("x>=y: %d\n",(x>=y));
	printf("x<=y: %d\n",(x<=y));
	printf("x==y && x>y: %d \n",(x==y && x>y));
	printf("x==y && x<y: %d \n",(x==y && x<y));
	printf("x==y || x>y: %d \n",(x==y || x>y));
	printf("x==y || x<y: %d \n",(x==y || x<y));
	return EXIT_SUCCESS;
}
