/*
 ============================================================================
 Name        : 14_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void changeNumber(int a);

//global variables
int a =0;
int b=0;
int c=0;

int main(void) {
printf("a = %d\n",a);
changeNumber(a);
printf("b = %d\n",b);
printf("c = %d\n",c);
	return EXIT_SUCCESS;
}
void changeNumber(int a){
	a=-2;
	b=3; // not declared because global variable. will be changed to 3.
	int c=4;
	printf("a_change=%d\n",a);
	printf("b_change=%d\n",b);
	printf("c_change=%d\n",c);// global variable superseded by local variable.
	//c is local to this function since it has been declared here.
}

