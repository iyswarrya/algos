/*
 ============================================================================
 Name        : factorial.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int factorial=1;
	printf("enter n:\n");
	scanf("%d",&n);
	//printf("n is %d\n", n);
	int *ptr;
	ptr = &n;
	//printf("%d\n", *ptr);

	for(int i=1;i<=*ptr;i++)
	{
factorial = factorial * i;
printf("%d\n", factorial);
	}
	printf("factorial of %d is %d\n", n, factorial);
	return EXIT_SUCCESS;
}
