/*
 ============================================================================
 Name        : 11_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size[] = {15,20,30};
	int *ptr;
	ptr = &size;

	printf("Address %x contains the value %d\n",ptr,*ptr);

	ptr++;
	printf("Address %x contains the value %d\n",ptr,*ptr);

	ptr++;
	printf("Address %x contains the value %d\n",ptr,*ptr);

		ptr--;
		printf("Address %x contains the value %d\n",ptr,*ptr);


	return EXIT_SUCCESS;
}
