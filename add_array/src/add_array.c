/*
 ============================================================================
 Name        : add_array.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define n 5

int main(void) {
	int array[n] = {1,2,5,4,8};
	int *ptr = array;
	int add=0;
	 for(int i=1; i<=n; i++){
		 add = add + *(array+(i-1));
	 }
printf("%d", add);
	return EXIT_SUCCESS;
}
