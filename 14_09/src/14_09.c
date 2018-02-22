/*
 ============================================================================
 Name        : 14_09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

void generateFibonacci(int numbers){
	for(int i=0;i<=numbers;i++)
		printf("Fibonacci[%d]: %d\n",i,fibonacci(i));

}

int main(void) {
	generateFibonacci(10);
	return EXIT_SUCCESS;
}
