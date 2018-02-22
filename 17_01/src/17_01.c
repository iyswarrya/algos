/*
 ============================================================================
 Name        : 17_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ask_user(void);
void loan_payment(float loan_amount,float interest_rate,int years);

//Globals
float loan_amount, annual_rate;
int years;


int main(void) {
	ask_user();
	loan_payment(loan_amount,annual_rate,years);
	return EXIT_SUCCESS;
}

void ask_user(void){
	printf("Enter loan amount: $\n");
	scanf("%f",&loan_amount);
	printf("Enter annual_interest_rate: \n");
	scanf("%f",&annual_rate);
	printf("Enter the number of years: \n");
	scanf("%d",&years);
}

void loan_payment(float loan_amount,float annual_rate,int years){
	int n= years * 12;
	float i,discount;
	float loan_payment,total_payback;
	//printf("Enter annual rate \n");
	//scanf("%f",&annual_rate);
	i = (annual_rate/100)/12;
	discount = ((pow(1+i,n))-1)/(i*pow(1+i,n));
	loan_payment = loan_amount / discount;
	total_payback = loan_payment * n;
	printf("The loan amount to be paid is $%f\n",loan_payment);
	printf("The total payback amount is $%f \n",total_payback);
}
