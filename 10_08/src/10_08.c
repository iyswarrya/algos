/*
 ============================================================================
 Name        : 10_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 18

void generateDataSet();

#include <stdio.h>
#include <stdlib.h>

void singleDot(void);
void barChart(int k);

int main(void) {
	int dataSet[SIZE];
	generateDataSet(dataSet,SIZE);

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

void generateDataSet(int dataset[],int len){
	int i;
	srand(time(NULL));
	for(i=0;i<len;i++) {
	dataset[i]=rand() %50;
	printf("dataset[%d]: %3d :",i,dataset[i]);
	barChart(dataset[i]);
	}

}

