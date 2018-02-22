/*
 ============================================================================
 Name        : 03_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float floatNo;
	double doubleFloatNo;
	long double longDoubleNo;

	puts ("memory size of each type\n");
	puts ("------------------------\n");

	printf ("storage size of float: %lu bytes\n",sizeof(float));
	printf ("storage size of double: %lu bytes\n",sizeof(double));
	printf ("storage size of long double: %lu bytes\n\n",sizeof(long double));

	floatNo = 2.0/3.0;
	doubleFloatNo = 2.0/3.0;
	longDoubleNo = 2.0/3.0;

	printf("comparison of precision to 10 decimal points\n");
	printf("float = %1.10f\n",floatNo);
	printf("doubleFloat= %1.10lf\n",doubleFloatNo);
	printf("longDoubleNo= %1.10Lf\n\n",longDoubleNo);

	printf("comparison of precision to 30 decimal points\n");
	printf("float = %1.30f\n",floatNo);
	printf("doubleFloat= %1.30lf\n",doubleFloatNo);
	printf("longDoubleNo= %1.30Lf\n",longDoubleNo);

}
