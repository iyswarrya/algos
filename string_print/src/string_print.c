/*
 ============================================================================
 Name        : string_print.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int main(void) {
	char name[10] = "iyswarya";
	for (int i=0;i<10;i++){
		printf("%c\t",name[i]);
	}
	return 0;
}
