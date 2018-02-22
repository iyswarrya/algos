/*
 ============================================================================
 Name        : 09_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void whileLoop(int n);
void getData(void);

int main(void) {

	whileLoop(1);
	getData();
	return EXIT_SUCCESS;
}

void whileLoop(int n){
	int flag = FALSE;
	while(!flag){
		printf("%d\n",n);
		n++;
		if(n>=10)
			flag = TRUE;
	}

}
void getData(void){
	char c=0;
	while(c !='x'){
		printf("enter the letter\n");
		c = getchar();
	}

		printf("you entered x and loop stopped\n");
}
