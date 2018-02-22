/*
 ============================================================================
 Name        : 06_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x=10;// takes binary equivalent of 10
	int y=5;//takes binary equivalent of 5
// bit wise operations
	printf("x&y is %d\n",(x&y));//answer will be the decimal equivalent of the binary result
	printf("x|y is %d\n",(x|y));
	printf("x^y is %d\n",(x^y));
	printf("x>>1 is %d\n",(x>>1));
	printf("y<<1 is %d\n",(y<<1));


}
