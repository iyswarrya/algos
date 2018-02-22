/*
 ============================================================================
 Name        : 07_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float amount,balance,update_balance;
void initializeAccount();
void getBalance(void);
void askCustomer(void);
void updateAccount(float value);
void addGift(float gift);
void thankYou(void);


int main(void) {
	initializeAccount();
	getBalance();
	//1st transaction
	askCustomer();
	updateAccount(amount);
	thankYou();
	//second transaction
	askCustomer();
	updateAccount(amount);
	addGift(10);
	thankYou();
	//third transaction
	askCustomer();
	updateAccount(amount);
	addGift(2);
	thankYou();
	return EXIT_SUCCESS;
}

void initializeAccount(void) {
	amount =0.0;
	printf("initial amount: %f\n",amount);

}

void getBalance(void) {

	printf("balance is %f\n",balance);
}

void askCustomer(void) {
	printf("next transaction plz\n");
	printf("Enter the amount you would like to credit or debit");
	scanf("%f",&amount);
}

void updateAccount(float amount) {
	balance = amount + balance;
	printf("updated account value is %f\n",balance);

}

void addGift(float gift){
	balance = gift +balance;
	printf("balance after adding %f gift amount: %f\n", gift, balance);
}
void thankYou(void) {
	printf("thank you for the transaction\n");
}
