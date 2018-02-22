/*
 ============================================================================
 Name        : 09_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void listOfEvenNumbers(void);
void listOfOddNumbers(void);

int main(void) {
	listOfEvenNumbers();
	listOfOddNumbers();
	return EXIT_SUCCESS;
}

void listOfEvenNumbers(void){
	int i;
	for(i=0;i<=100;i+=2) {
		printf("%d\n",i);
	}
}
void listOfOddNumbers(void){
	int i;
	for(i=1;i<=100;i+=2) {
		printf("%d\n",i);
	}
}
