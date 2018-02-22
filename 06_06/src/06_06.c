/*
 ============================================================================
 Name        : 06_06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int main(void) {

	int R;
	float areaOfCircle;
	printf("enter R");
	scanf("%d",&R);
	areaOfCircle = PI * R * R;
	printf("Area of circle is %f\n",areaOfCircle);


	//roots for quadratic equation aX^2+bX+c=0

	float x1,x2;
	float a=2;
	float b=4;
	float c=2;

	float discriminant = sqrt(b*b - 4*a*c);
	// sqrt can be taken in C only for positive values.choose a,b,c accordingly.
	x1 = (-b + discriminant) / (2*a);
	x2 = (-b - discriminant) / (2*a);

	printf("first root is %f\n", x1);
	printf("second root is %f\n", x2);

}
