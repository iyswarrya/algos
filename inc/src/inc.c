/*
 ============================================================================
 Name        : inc.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <file.c>

int main(void) {
	int num;
	printf("enter num\n");
		scanf("%d",&num);
	square(num);
	return EXIT_SUCCESS;
}
