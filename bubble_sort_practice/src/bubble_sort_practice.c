/*
 ============================================================================
 Name        : bubble_sort_practice.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[],int size);

int main(void) {
	int array[] = {5,2,10,13,7};
	int size = sizeof(array) /sizeof(int);
	bubbleSort(array,size);
	return 0;
}

void bubbleSort(int array[],int size){

	printf("size %d\n",size);

	for(int i = 0;i<size-1;i++){
		for(int j = 0;j<size-i-1;j++){
			if(array[j]>array[j+1]){
				int temp = array [j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
		for(int k=0;k<size;k++){
				printf("%d\n",array[k]);
			}

	return;
}
