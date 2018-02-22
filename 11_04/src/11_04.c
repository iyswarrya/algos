/*
 ============================================================================
 Name        : 11_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int staticArray[20]={2,3};

	int *dynamicArray = malloc (20 * sizeof(int));
	*dynamicArray = 10;
	dynamicArray[1]=20; // 2nd element of the array

	printf("The size of staticArray is %d\n",sizeof(staticArray));
	printf("the elements in the dynamic array are %d and %d\n",dynamicArray[0],dynamicArray[1]);
	printf("size of dynamicArray is %d",sizeof(dynamicArray));

	return EXIT_SUCCESS;
}
