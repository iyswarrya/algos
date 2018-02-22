/*
 ============================================================================
 Name        : 08_04.c
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
void stopDriving(void);
void getReady(void);
void go(void);
void trafficLightMalFunction(void);

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
	switch(c) {
	case 'r':
		stopDriving();
		break;
	case 'y':
		getReady();
		break;
	case 'g':
		go();
		break;
	default: trafficLightMalFunction();
	}
	}
void stopDriving(void){
	printf("stopDriving\n");
}

void getReady(void){
	printf("getReady\n");
}
void go(void) {
	printf("go\n");
}
void trafficLightMalFunction(void){
	printf("traffic light mal function\n");

}
