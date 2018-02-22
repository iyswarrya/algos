/*
 ============================================================================
 Name        : merge_sort_practice.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void mergeSort(int array[],int firstPosition,int lastPosition);
void merge(int array[],int firstPosition,int midpoint,int lastPosition);

int main(void) {
	int array[]={5,2,7,3,4,8,1,9};
	int n = sizeof(array) / sizeof(int);
	mergeSort(array,0,n-1);
	for(int p=0;p<n;p++){
			printf("%d\n",array[p]);
		}
	return 0;
}


void merge(int array[],int firstPosition,int midpoint,int lastPosition){
	int tempArray[lastPosition-firstPosition+1];
	int tempCounter = 0;
	int originalstartposition = firstPosition;
	int rightfirstPosition = midpoint+1;

	while(firstPosition <= midpoint && rightfirstPosition <= lastPosition){
		if(array[firstPosition] < array[rightfirstPosition]){
			tempArray[tempCounter] = array[firstPosition];
			tempCounter++;
			firstPosition++;
		}
		else {
			tempArray[tempCounter] = array[rightfirstPosition];
			tempCounter++;
			rightfirstPosition++;
		}
	}

	//if(firstPosition <= midpoint){
		while(firstPosition <= midpoint){
			tempArray[tempCounter] = array[firstPosition];
			tempCounter++;
			firstPosition++;
		}
	//}

	//if(rightfirstPosition <= lastPosition){
		while(rightfirstPosition <= lastPosition){
			tempArray[tempCounter] = array[rightfirstPosition];
			tempCounter++;
			rightfirstPosition++;
		}
	//}

	//printf("%d",tempCounter);
	for(int i =0;i<tempCounter; i++){
		array[originalstartposition++] = tempArray[i];
	}
}

void mergeSort(int array[],int firstPosition,int lastPosition){
	if(firstPosition == lastPosition){
		return;
	}

	int midpoint = (firstPosition+lastPosition)/2;
	mergeSort(array,firstPosition,midpoint);
	mergeSort(array,midpoint+1,lastPosition);
	merge(array,firstPosition,midpoint,lastPosition);

}
