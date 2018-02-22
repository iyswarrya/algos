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

void merge( int array[], int first,int midpoint,int last){
	int i,j,k;

	int Lcount = midpoint - first+1;
	int Rcount = last - (midpoint);
	printf("Lcount: %d   Rcount: %d\n", Lcount, Rcount);
	int L[Lcount];
	int R[Rcount];

	for(i=0;i<Lcount;i++){
		L[i]=array[first+i];
	}
	for(j=0;j<Rcount;j++){
		R[j]=array[midpoint+1+j];
	}

	i=j=0;
	k=1;
	int Lvounter=0;
	int Rvounter = 0;
	while(i<Lcount && j<Rcount){
		//printf("!!!\n");
		if( L[i]<= R[j]){
			//printf("\\\\\\");
			L[i] = array[k];
			i++;
			Lvounter++;
		}
		else {
			//printf("|||||||||\n");
			R[j] = array[k];
			j++;k++;
			Rvounter++;
		}
	}
	printf("i=%d,j=%d,k=%d\n",i,j,k);
	while(i<Lcount){
		//printf("aaaaaaaaaaa\n");
		L[i++] = array[k++];
		Lvounter++;
	}
	while(j<Rcount){
		//printf("bbbbbbbbbb\n");
		R[j++] = array[k++];
		Rvounter++;

	}

	for(int i=0;i<Lvounter;i++){
		array[first++]=L[i];
	}

	for(int i=0;i<Rvounter;i++){
			array[midpoint++]=R[i];
		}
}

void merge_sort( int array[], int first,int last){

	if(first < last){
	int midpoint = (first + (last-1))/2;
	printf("first: %d, last: %d\n",first, last);
	printf("midpoint: %d\n",midpoint);

	merge_sort(array,first,midpoint);
	merge_sort(array,(midpoint+1),last);

	merge(array,first,midpoint,last);
	}
	else{
		return;
	}
	}





