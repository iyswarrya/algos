/*
 ============================================================================
 Name        : 05_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int originalValue, tax, discount,finalPrice;
	double afterTax,discountValue;
	printf("originalValue=");
	scanf("%d",&originalValue);
	printf("tax=");
	scanf("%d",&tax);
	printf("discount=");
	scanf("%d",&discount);
	afterTax = originalValue*(1.0+tax/100.0);
	discountValue=originalValue*(discount/100.0);
	printf("afterTax = %0.5f\n",afterTax);
	printf("discountValue = %0.5f\n",discountValue);
	finalPrice = afterTax-discountValue;
	printf("finalPrice =%d",finalPrice);

	return EXIT_SUCCESS;
}
