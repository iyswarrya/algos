/*
 ============================================================================
 Name        : 03_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // standard library for boolean type


// to manually define boolean type
typedef int Bool; // defining Bool to be int type
#define True 1
#define False 0

int main(void) {
	Bool aBooleanNo;
	aBooleanNo = True;
	printf ("value of aBooleanNo is %d",aBooleanNo);
}
