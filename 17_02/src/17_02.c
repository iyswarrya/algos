/*
 ============================================================================
 Name        : 17_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main() {
	unsigned int value;
	printf("Enter value = %d\n");
	scanf("%d",&value);
	int count = 0;
	while(value>0){
		if(value & 1)
			count++;
		value>>1;
	}
	printf("Number of 1's = %d\n",count);
}
