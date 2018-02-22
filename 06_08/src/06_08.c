/*
 ============================================================================
 Name        : 06_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	int height_feet;
	double height_inch,height_cm;
	printf("enter height in cms : ");
	scanf("%lf",&height_cm);
	double inches = height_cm / 2.54;
	height_feet = inches / 12; // 12 inches in a foot
	double height = inches - (height_feet * 12);
	printf("height is %d feet and %lf inches\n",height_feet,height);

	return EXIT_SUCCESS;
}
