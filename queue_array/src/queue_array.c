/*
 ============================================================================
 Name        : queue_array.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define n 4

int front = -1;
int rear = -1;
int queue[n];

void enqueue(){
	int val;

	if(rear == n-1){
		printf("queue is full\n");
	}
	else{
	front =0;
	printf("enter the value\n");
	scanf("%d",&val);
	rear = rear +1;
	queue[rear] = val;
	}

}

void dequeue(){
	if(front == -1 || front >rear){
			printf("queue underflow\n");
			return;
		}
	else
	{	printf("dequeued element is %d from position %d\n",queue[front],front);
		front=front+1;
	}

	return;
}

void display(){
	if(front == -1){
		printf("queue empty\n");
	}
	else{
	printf("queue elements are\n");
		for(int i=front;i<=rear;i++){
				printf("%d\t",queue[i]);
			}
	}
}

int menu(){
	int ch;
	printf("enter a choice: 1.enqueue 2.dequeue 3.display 4.exit\n");
	scanf("%d",&ch);
	return ch;
}

int main(void){
	int ch;
	do{
	ch = menu();

	switch(ch)
	{
	case 1:enqueue();
	break;
	case 2:dequeue();
	break;
	case 3:display();
	break;
	case 4:exit(1);
	default:printf("invalid choice\n");
	}
	}while(1);

return 0;
}
