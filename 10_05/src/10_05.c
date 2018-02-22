/*
 ============================================================================
 Name        : 10_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM_ROW 2
#define NUM_COL 3

void printTable(int table[][NUM_COL]);
int main(void) {
	int table[NUM_ROW][NUM_COL]={{132,150,12},{120,15,129}};
	printf("the element in the 2nd row and 3rd column is %d\n",table[1][2]);
	printTable(table);
	return EXIT_SUCCESS;
}

void printTable(int table[][NUM_COL]){
	printf("----table----\n");
	for(int i=0;i<NUM_ROW;i++) {
		for(int j=0;j<NUM_COL;j++){
			printf("%4d",table[i][j]);
		}
		printf("\n");
	}
}

