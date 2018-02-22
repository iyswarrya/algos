/*
 ============================================================================
 Name        : queue_final.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#define N 4

typedef struct queue{
int front;
int rear;
int * data;
} queue_t;


void enqueue(queue_t * queue, int value){
	if((queue->rear == N-1 && queue->front ==0) || (queue->rear<queue->front && queue->front-queue->rear==1)){
		printf("Queue full\n");
		return;
	}

	if(queue->rear != N-1 && queue->front <= queue->rear ){
		if(queue->rear == -1 && queue->front ==-1){
			printf("####\n");
			queue->rear =0;
			queue->front =0;
			queue->data[front] = 0;
		}
		else{
			//printf("%d\n",*(queue+front));
			(queue->rear)++;
			*(queue+queue->rear) = value;
		}
	}

	if(queue->rear == N-1 && queue->front !=0){
		queue->rear = -1;
		queue->rear++;
		*(queue+queue->rear) = value;
	}
}


int dequeue(queue_t *queue){
	int dequeued_value;

	if((queue->rear == -1 && queue->front ==-1) || (queue->front>queue->rear &&  queue->front!= N-1)){
		printf("Queue empty\n");
		return NULL;
	}

	if(queue->front == N-1){
		dequeued_value = *(queue+(queue->front));
		queue->front = 0;
		return dequeued_value;
	}
	else{
		dequeued_value = *(queue+(queue->front));
		*(queue+(queue->front)) = 0;
		queue->front++;
		return dequeued_value;
	}
}

int main(){
	queue_t * queue[N];
	enqueue(queue, 6);
	enqueue(queue, 4);
	enqueue(queue, 3);
	enqueue(queue, 7);
	for(int i = 0;i < 4;i++){
		printf("%d\n",*(queue+i));
	}
	printf("dequed: %d\n",dequeue(queue));
	printf("dequed: %d\n",dequeue(queue));
	enqueue(queue, 71);
	for(int i = queue->front;i < N;i++){
		printf("%d\n",*(queue+i));
	}
	if(queue->rear < queue->front){
		for(int i = queue->rear;i < queue->front;i++){
			printf("%d\n",*(queue+i));
		}
	}
	return 0;
}
