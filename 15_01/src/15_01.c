/*
 ============================================================================
 Name        : 15_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define max(X,Y)  ((X>Y) ? (X) : (Y))

int main(void) {
	int *p,*q,n;
	int val1=5;
	int val2=12;
	p = &val1; //address of val1 stored
	q = &val2;
	n = 1;
	int x = max(p,q);
	int y = max(12,6);
	int z = max(n+8,*p);
	printf("x = %d\ny = %d\nz=%d \n",x,y,z);
	return EXIT_SUCCESS;
}
