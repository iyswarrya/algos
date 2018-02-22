/*
 ============================================================================
 Name        : 08_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define selling_point 102.0
#define purchase_point 50.2

void purchaseDecision(float value);
void handleDecision(char action);

int main(void) {
	float stock;
	printf("enter the current stock value\n");
	scanf("%f",&stock);
	purchaseDecision(stock);
	return EXIT_SUCCESS;
}

void purchaseDecision(float value){
	if(value > selling_point)
		handleDecision('s');
	else if(value <purchase_point)
	 handleDecision('b');
	else handleDecision('h');
}

void handleDecision(char action) {
	switch(action) {
	case('s'):
			printf("sell the stock");
			break;
	case('b'):
			printf("buy more stocks");
			break;
	case('h'):
			printf("hold");
			break;
	}
}
