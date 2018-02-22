/*
 ============================================================================
 Name        : 09_06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void singleDot(void);
void barChart(int k);

int main(void) {
	
	barChart(10);
	barChart(2);
	barChart(15);
	barChart(30);
	return EXIT_SUCCESS;
}

void singleDot(void) {

	printf("•");
}


void barChart(int k){
	int n=1;
	for(n=1;n<=k;n+=1)
		singleDot();
		printf("\n");

}
