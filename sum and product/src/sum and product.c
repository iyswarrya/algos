/*
 ============================================================================
 Name        : sum.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*void sum_product(int *ptr1, int *ptr2,int i,int j);
int main(void) {
	int x=10;
	int y =20;
	int sum;
	int product;
	sum_product(&sum,&product,x,y);
	printf("sum: %d  product: %d",sum,product);
	return EXIT_SUCCESS;
}

void sum_product(int *ptr1, int *ptr2,int i,int j){
	*ptr1 = i+j;
	*ptr2 = i*j;
}*/

int main(){
	int x = 100;
	int y = 3;
	float z=0;
	z = (float)x/y;
	printf("%f",z);
	return 0;
}
