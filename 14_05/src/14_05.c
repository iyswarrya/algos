/*
 ============================================================================
 Name        : 14_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void someFunction(int a, int b);
void someOtherFunction(int *a,int *b);
int main(void) {

	printf("---By Value----\n");
	int a =0;
	int b=0;
	printf("Before calling function a=%d , b=%d\n",a,b);
	someFunction(a,b);
	printf("After calling function a=%d , b=%d\n",a,b);


	printf("---By Reference----\n");
	a = 0;
	b = 0;
	printf("Before calling function a=%d , b=%d\n",a,b);
	someOtherFunction(&a,&b);
	printf("After calling function a=%d , b=%d\n",a,b);
	return EXIT_SUCCESS;
}

void someFunction(int a , int b){
	printf("in function received: a=%d , b=%d\n",a,b);
	a=3;
	b=2;
	printf("in function modified: a=%d , b=%d\n",a,b);
}

void someOtherFunction(int *a , int *b){
	printf("in function received: a=%d , b=%d\n",*a,*b);
	*a=3;
	*b=2;
	printf("in function modified: a=%d , b=%d\n",*a,*b);
}
