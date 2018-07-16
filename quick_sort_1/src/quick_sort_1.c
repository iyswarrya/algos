/*
 ============================================================================
 Name        : quick_sort_1.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void quickSort(int array[],int firstPosition,int lastPosition);

int main(void) {
	int array[]={7,5,1,9,0,8,2};
	int size = sizeof(array)/sizeof(int);
	quickSort(array,0,size-1);
	for(int j =0;j<size;j++){
		printf("%d\n\n\n\n\n",array[j]);
	}

	return 0;
}

void quickSort(int array[],int firstPosition,int lastPosition){

	int pivot = lastPosition;
	int firstPosition_i = firstPosition;

	if(firstPosition > pivot){
		return;
	}

	//for loop didn't work because after swapping the elements, the new element in the
	//ith position should again be compared with the pivot element

	while(firstPosition != pivot){
		if(array[firstPosition] < array[pivot]){
			firstPosition++;
		}
		else if (array[firstPosition] > array[pivot]){
			int temp = array[pivot-1];
			array[pivot-1]= array[pivot];
			array[pivot]=array[firstPosition];
			array[firstPosition]=temp;
			pivot--;
		}
	}
	quickSort(array,firstPosition_i,pivot-1);
	quickSort(array,pivot+1,lastPosition);
	return;
}
