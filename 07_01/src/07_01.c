/*
 ============================================================================
 Name        : 07_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int room1,room2,room3;
	float visitor_r1,visitor_r2,visitor_r3;
	int totalSeats, totalVisitors;
	void numberOfSeats(void);
	void waitingVisitors(void);
	void processData(void);
	void generateReport(void);


int main(void) {
	numberOfSeats();
	waitingVisitors();
	processData();
	generateReport();
	}

void numberOfSeats() {
	printf("enter number of seats in room1: \n");
	scanf("%d",&room1);
	printf("enter number of seats in room2: \n");
	scanf("%d",&room2);
	printf("enter number of seats in room3: \n");
	scanf("%d",&room3);
}
void waitingVisitors() {
	printf("enter number of visitors in room1: \n");
	scanf("%f",&visitor_r1);
	printf("enter number of visitors in room2: \n");
	scanf("%f",&visitor_r2);
	printf("enter number of visitors in room3: \n");
	scanf("%f",&visitor_r3);
}
void processData(){
	totalSeats = room1 + room2 + room3;
	totalVisitors = visitor_r1+visitor_r2+visitor_r3;
}
void generateReport(){
	printf("Can room1 accept more visitors? yes=1 or no=0: %d \n",(room1>visitor_r1));
	printf("Can room2 accept more visitors? yes=1 or no=0: %d \n",(room2>visitor_r2));
	printf("Can room3 accept more visitors? yes=1 or no=0: %d \n",(room3>visitor_r3));
	printf("average number of visitors per room is %0.2f",(visitor_r1+visitor_r2+visitor_r3)/3);
}
