/*
 ============================================================================
 Name        : inserion.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array [] = {34,76,5,89,26,19,55,22,54,9};
	int size = sizeof(array)/sizeof(int);
	//printf("%d\n",size);

	for(int i=0;i<size-1;i++){
		if(array[i] >array[i+1]){
		int temp=array[i];
		array[i]=array[i+1];
		array[i+1]=temp;
		}
		for(int j=i;j>=0;j--){
			if(array[j]<array[j-1]){
				int temp=array[j];
				array[j]=array[j-1];
				array[j-1]=temp;
			}

		}

	}
for(int k=0;k<size;k++){
	printf("%d\n",array[k]);
}

}
