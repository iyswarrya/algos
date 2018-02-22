/*
 ============================================================================
 Name        : 03_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts ("memory size of each type");
	puts ("------------------------");

	printf("storage size for unsigned long: %lu bytes\n", sizeof(unsigned long));
	printf("storage size of signed char: %lu bytes\n", sizeof(signed char));
	printf("storage size of void: %lu bytes\n", sizeof(void));
}
