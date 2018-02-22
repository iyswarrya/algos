/*
 ============================================================================
 Name        : 09_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void breakTest(void);
int main(void) {
	breakTest();
	return EXIT_SUCCESS;
}

void breakTest(void){
	int loopCounter=1;
			int n;
	while(1){
		printf("cycle[%d]: enter the number\n",loopCounter);
		scanf("%d",&n);

		if(n==0 || loopCounter>=10)
			break;
		loopCounter++;
	}
}
