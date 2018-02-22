/*
 ============================================================================
 Name        : circ_queue.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define n 3

int queue[n];
int front = -1;
int rear = -1;


void enqueue(){
	int value;
	if(front == rear + 1  || (front == 0 && rear ==n-1)){
		printf("queue is full\n");
		return;
	}
		if(front == -1) {
			front =0;
		}

		if(rear == n-1 && front !=0){
			rear = -1;
		}

		printf("enter the value\n");
		scanf("%d",&value);
		rear=(rear+1);
		queue[rear] = value;

}

void dequeue(){
	if(front == -1){
		printf("queue is empty\n");
		return;
	}

	else {
		int dequeued = queue[front];
		printf("dequeued element is %d from position %d\n",dequeued,front);
		front = front +1;


	if(front == n){
			front = 0;
		}

	if(front-1 == rear)
		 front = rear = -1;
}
}

void display(){
	if(front == -1){
		printf("queue empty\n");
	}
	else{
	printf("queue elements are\n");
	printf("front:%d, rear:%d\n",front,rear);

	if(rear>=front){
	for(int i=front;i<=rear;i++){
					printf("%d\t",queue[i]);
				}
	}
	else {
		for(int j=front;j<=n-1;j++){
			printf("%d\t",queue[j]);
		}
		for(int k=0;k<=rear;k++){
					printf("%d\t",queue[k]);
				}
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

