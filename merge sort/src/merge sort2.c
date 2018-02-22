/*
 ============================================================================
 Name        : merge.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void merge( int array[], int first,int midpoint,int last);
void merge_sort( int array[], int first,int last);


int main(void) {
	int array[]={5,2,7,3,4,8,1,9};
	int n = sizeof(array)/sizeof(int);
	printf("size of array:%d\n",n);
	merge_sort(array,0,n-1);
	for(int p=0;p<n;p++){
		printf("%d\n",array[p]);
	}
	return 0;
}

void merge(int array[], int lowpointer1,int highpointer1,int highpointer2){
	//lowpointer, highpointer - denotes start and end pointers of a subarray - suffixed with 1/2 for two subarrays
	int temparray[highpointer2-lowpointer1+1];

	int temparraycounter = 0;
	//mid point of the array -  not a pointer that moves with every iteration
	int midpoint = lowpointer1;

	int lowpointer2 = highpointer1+1;

	//printf("%d=lowpointer1\t\t%d=highpointer1\t\t%d=lowpointer2\t\t%d=highpointer2\n\n",lowpointer1, highpointer1,lowpointer2, highpointer2);

	while(lowpointer1<=highpointer1 && lowpointer2<=highpointer2){
		if(array[lowpointer1] < array[lowpointer2]){
			temparray[temparraycounter] = array[lowpointer1];
			temparraycounter++;
			lowpointer1++;
		}else{
			temparray[temparraycounter] = array[lowpointer2];
			temparraycounter++;
			lowpointer2++;
		}
	}

	if(lowpointer1 <= highpointer1){
		while(lowpointer1<=highpointer1){
			temparray[temparraycounter++] = array[lowpointer1++];
		}
	}

	if(lowpointer2 <= highpointer2){
		while(lowpointer2<=highpointer2){
			temparray[temparraycounter++] = array[lowpointer2++];
		}
	}

	for(int i=0; i<temparraycounter; i++){
		//printf("%d\n", temparray[i]);
		array[midpoint++] = temparray[i];
	}

}



void merge_sort( int array[], int start,int end){

	if(start == end){
		return;
	}
	int midpoint = (start + end)/2;

	merge_sort(array,start,midpoint);
	merge_sort(array,midpoint+1,end);

	merge(array,start,midpoint,end);

}





