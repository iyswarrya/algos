/*
 ============================================================================
 Name        : 09_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getData(void);
void getData1(void);
int main(void) {
	//getData();
	getData1();
	return EXIT_SUCCESS;
}
void getData(void){
	char c= 'x';
	int testVariable=999;
	while(c !='x'){
		printf("testVariable = %d\n",testVariable);
		printf("enter the letter\n");
		c = getchar();
	}

		printf("you entered x and loop stopped\n");
}
void getData1(void){
	char c= 'x';
	int testVariable=999;
	do{
		printf("testVariable = %d\n",testVariable);
		printf("enter the letter\n");
		c = getchar();
	}while(c !='x');

		printf("you entered x and loop stopped\n");
}
