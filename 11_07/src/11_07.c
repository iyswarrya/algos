/*
 ============================================================================
 Name        : 11_07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAMELENGTH 10   // MAXIMUM NAME LENGTH
#define MAX_COLOR 10 // maximum color length
#define MAX_TEAMS 10
#define MAX_NAMES 4
#define MAX_COLORS 4
#define MAX_AGE 120


struct person{
	char firstName[MAX_NAMELENGTH];
	char lastName[MAX_NAMELENGTH];
	int age;
	char eyecolor[MAX_COLOR];
};
void printArray(void);
void populateArray(void);
char bankOfFirstNames[MAX_NAMES][MAX_NAMELENGTH]= {"sita","rita","das","tom"};//2D because each name is an array of characters
	//char bankOfLastNames[MAX_NAMES][MAX_NAMELENGTH]

	struct person teams[MAX_TEAMS];
int main(void) {
	populateArray();
	printArray();
	return EXIT_SUCCESS;
}

void populateArray(void){
	srand(time(NULL));

	for(int i=0;i<MAX_TEAMS;i++){
		int rF= rand() % MAX_NAMES;
		strcpy(teams[i].firstName,bankOfFirstNames[rF]);
		teams[i].age=rand() % MAX_AGE;
	}


}
void printArray(void){
	for(int i=0;i<MAX_TEAMS;i++){
printf("First name:[%8s] \n",teams[i].firstName);
printf("Age:[%3d] \n",teams[i].age);
	}
}


