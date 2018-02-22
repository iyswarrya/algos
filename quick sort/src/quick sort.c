/*
 ============================================================================
 Name        : quick.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[],int first,int end);

int main(void) {
	int a[]={10,80,30,90,40,50,70};
	int n = sizeof(a)/sizeof(int);
	int first =0;
	int end = n-1;
	for(int i=0;i<n;i++){
			printf("%d\n",a[i]);
		}
	quicksort(a,first,end);
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}

void quicksort(int a[],int first,int end){

	int pivot = end;
	if(first > pivot){
		printf("\n====================\n");
		printf("\nstart first %d\n", first);
		printf("\nstart pivot %d\n", pivot);
		return;
	}


		//int pivot = end;
		printf("\n&&&&&&&&&&&&&&&&&&\n");
		printf("\nstart pivot %d\n", pivot);
		int first_i = first;
		while(first != pivot){
			if(a[first] < a[pivot]){
				first++;
			}
			if(a[first] > a[pivot]){
				int p = a[first];
				a[first]=a[pivot-1];
				a[pivot-1]=a[pivot];
				a[pivot]=p;
				pivot--;
			}
		}
		printf("\n end pivot: %d\n", pivot);
		quicksort(a,first_i,pivot-1);
		quicksort(a,pivot+1,end);

	return;
}
