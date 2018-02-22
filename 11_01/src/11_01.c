/*
 ============================================================================
 Name        : 11_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 15;
	int *ptr;
	ptr = &size;
	printf("Address %x contains %d",ptr,*ptr);

	return EXIT_SUCCESS;
}
