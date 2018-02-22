/*
 ============================================================================
 Name        : 14_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int smallest(int x, int y);

int main(void) {
	int n = smallest(3,7);
	printf("n = %d",n);
	return EXIT_SUCCESS;
}
int smallest(int x, int y){
	int minVal;
	if(x>y)
		minVal = y;
	else minVal = x;
	return minVal;
}
