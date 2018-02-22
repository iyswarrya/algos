/*
 ============================================================================
 Name        : 10_07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void printArray(float dataset[], int len);
void searchHighMPG(float value,float dataset[],int len);
void sortArray(float dataset[],int len);
int main(void) {
	float MPGdata[10] = { 5.0,20.0,30.0,15.0,22.0,13.0,18.0,41.0,36.0,19.2};
	searchHighMPG(30.0,MPGdata,10);
	printArray(MPGdata,10);
	sortArray(MPGdata,10);

	return EXIT_SUCCESS;
}

void printArray(float dataset[], int len){
	int i;
	printf("\n The car MPG's are:\n");
	for(i=0;i<len;i++)
	printf("MPGdata[%d]: %f\n",i,dataset[i]);
}

void searchHighMPG(float value,float dataset[],int len){
	int i;
	printf("High MPG values are\n");
	for(i=0;i<len;i++){
		if(dataset[i]>value)
			printf("MPGdata[%d]: %f\n",i,dataset[i]);
	}
}

void sortArray(float dataset[],int len) {

	int i;
	int loopcounter=0;
	int swapped;
	do{
		loopcounter++;
	swapped = FALSE;
	for(i=1;i<len;i++){
		if(dataset[i-1]>dataset[i]){
			float temp = dataset[i-1];
			dataset[i-1]=dataset[i];
			dataset[i]=temp;
			swapped = TRUE;
		}
	}
	printf("-----loop [%d]--------\n",loopcounter);
	printArray(dataset,len);
} while(swapped);
}
