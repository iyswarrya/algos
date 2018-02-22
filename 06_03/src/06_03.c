/*
 ============================================================================
 Name        : 06_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int minivan;
	int wagon;
	int weather;
	int readiness;
	int supermarket;
	int decision;

	printf("minivan: good=1 or bad=0");
	scanf("%d",&minivan);
	printf("wagon: good=1 or bad=0");
	scanf("%d",&wagon);
	printf("weather: good=1 or bad=0");
	scanf("%d",&weather);
	printf("readiness: good=1 or bad=0");
	scanf("%d",&readiness);
	printf("supermarket: good=1 or bad=0");
	scanf("%d",&supermarket);

decision = ((minivan || wagon) && weather && (readiness || supermarket));

printf("decision: good or bad  : %d",decision);

	return EXIT_SUCCESS;
}
