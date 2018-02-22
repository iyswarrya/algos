/*
 ============================================================================
 Name        : 10_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_ROOMS 20

void printArray(char dataname[], int dataset[], int datavalue);

int main(void) {
	int classroom[NUMBER_OF_ROOMS]={10,12,3,15,3};
	classroom[2]+= 2;
	printf("The 3rd element is %d\n",classroom[2]);
	printArray("classroom",classroom,NUMBER_OF_ROOMS);//"classroom" is a string array.
	//Each alphabet is stored in an array index.
	return EXIT_SUCCESS;
}

void printArray(char dataname[], int dataset[], int datavalue){
	int i=0;
	for(i=0;i<NUMBER_OF_ROOMS;i+=1)
	printf("%s[%d]:%d\n",dataname,i,dataset[i]);
}
