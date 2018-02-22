/*
 ============================================================================
 Name        : 11_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int data[]={15,20,25,30,35,40};
	int *ptr = data;// ptr points to the start of the array

	int num_elements = sizeof(data)/sizeof(int);
	printf("total data size:%d \n",sizeof(data));
	printf("single element size:%d \n",sizeof(int));
	printf("the number of elements in the array is %d\n",num_elements);

	for(int i=0;i<num_elements;i++){
			printf("\nAddress %x contains the value %d\n",ptr,*ptr);
			ptr++;
	}
	return EXIT_SUCCESS;
}
