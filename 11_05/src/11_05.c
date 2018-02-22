/*
 ============================================================================
 Name        : 11_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 20

struct person{
	int age;
	char  firstname[MAX_LENGTH];
	char lastname[MAX_LENGTH];
	float height;
	};

void printStructure(struct person individual);
int main(void) {
	struct person citizen;
	citizen.height = 5.9;
	citizen.age = 30;
	strcpy(citizen.firstname,"Ishu");
	strcpt(citizen.lastname,"Senthil");
	printStructure(citizen);

	return EXIT_SUCCESS;
}
void printStructure(struct person individual){
	printf("Height: %f\n",individual.height);
	printf("FirstName: %c\n",individual.firstname);
	printf("LastName: %c\n",individual.lastname);
	printf("Age: %d",individual.age);
}

