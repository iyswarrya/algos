/*
 ============================================================================
 Name        : 11_06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	strcpy(citizen.lastname,"Senthil");
	printStructure(citizen);
	char c = '@';
	printf("char :%c\n", c); // %c because it is not an array of characters.
	return EXIT_SUCCESS;
}
void printStructure(struct person individual){
	printf("Height: %f\n",individual.height);
	printf("FirstName: %s\n",individual.firstname);
	//%s because it is an array of char and forms a string
	printf("LastName: %s\n",individual.lastname);
	printf("Age: %d",individual.age);
}


