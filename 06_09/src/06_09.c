/*
 ============================================================================
 Name        : 06_09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double temp_C;
	double temp_F,temp_K;

	printf("Freezing point in C is %d\n",0);
	printf("Boiling point in C is %d\n",100);

	temp_C=0;
	temp_F = (temp_C *(1.8)) + 32;
		temp_K = (temp_C) + 273;
	printf("freezing points in F and K are %lf and %lf\n",temp_F,temp_K);

	temp_C=100;
	temp_F = (temp_C *(1.8)) + 32;
		temp_K = (temp_C) + 273;
	printf("Boiling points in F and K are %lf and %lf\n",temp_F,temp_K);
	return EXIT_SUCCESS;
}
