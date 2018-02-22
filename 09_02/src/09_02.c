/*
 ============================================================================
 Name        : 09_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void listOfEvenNumbers(void);
void listOfEvenRecursion(int k);

int main(void) {
	int k=0;
	listOfEvenNumbers();
	printf("--------------------\n");
	listOfEvenRecursion(k);
	return EXIT_SUCCESS;
}

void listOfEvenNumbers(void){
	int i;
	for(i=0;i<=100;i+=2) {
		printf("%d\n",i);
	}
}
void listOfEvenRecursion(int k){
	if(k<=100) {
		printf("%d\n",k);
		listOfEvenRecursion(k+2);
	}
}
