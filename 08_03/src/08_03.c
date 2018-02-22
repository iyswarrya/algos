/*
 ============================================================================
 Name        : 08_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void checkTrafficLights(void);
void processColor(char c);
int main(void) {

	checkTrafficLights();
	return EXIT_SUCCESS;
}
void checkTrafficLights(void){
	printf("enter the color of traffic light RED=r  YELLOW=y Green=g\n");
	char color;
	scanf("%c",&color);
	processColor(color);
}

void processColor(char c) {
	if(c == 'r')
		printf("red\n");
	else
		if(c =='y')
			printf("yellow\n");
		else
			printf("green\n");
}
