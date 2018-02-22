/*
 ============================================================================
 Name        : bubble.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array [] = {5,76,89,34,26,19,55,22,54,10};
	int size = sizeof(array)/sizeof(array[0]);
	for(int j=0;j<size-1;j++){
		for(int i=0;i<size-j-1;i++){
			if(array[i]> array[i+1]){
				int temp = array[i];
				array[i]=array[i+1];
				array[i+1]= temp;
			}
			printf("%d\t,",array[10-j]);
		}
		printf("\n");
	}
	printf("##########################after sorting,\n");
	for(int j=0;j<size;j++){
		printf("%d\n",array[j]);

	}


	return 0;
}

