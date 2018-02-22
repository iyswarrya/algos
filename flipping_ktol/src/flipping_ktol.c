/*
 ============================================================================
 Name        : flipping_ktol.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void flipping_KtoL(int x,int k,int l);
int main(void) {
	int x;
	flipping_KtoL(90,2,5);
	return EXIT_SUCCESS;
}

void flipping_KtoL(int x,int k,int l){
	int a = (1<<(k-1))-1;   //
	int b = (1<<l)-1;
	int mask = a^b;
	x = x^mask;
	printf("%d\n",x);
}

/* x = 90  -> 1011010
 * k=2
 * a = (1<<1)-1 = 10-1=01
 * b = (1<<5)-1 = 100000 = 011111
 * mask = a ^ b  = 011110
 * x ^ mask = 1011010 ^ 0011110 = 1000100 = 68
 * */

