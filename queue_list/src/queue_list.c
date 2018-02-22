/*
 ============================================================================
 Name        : queue_list.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


	typedef struct node {
		int key;
		struct node * next;
	}node;

	typedef struct queue {
		int data;
		struct node *rear, *front;
	}queue;

	node * create_node (int key){
		node * temp;
		temp = (node*)malloc(sizeof(node));
		temp->key = key;
		temp->next = NULL;
		return temp;
	}

	queue *create_queue(){
		queue * q;
		q = (queue*)malloc(sizeof(queue));
		q->front = q->rear = NULL;
		return q;
	}

	void enqueue(queue *q, int k){
		node * temp = create_node(k);

		if(q->rear == NULL){
			q->front = q->rear = temp;
		}

		q->rear->next = temp;
		q->rear = temp;
	}

	node *dequeue(queue *q){
		if(q->front == NULL){
			return NULL;
		}

		node * temp = q->front;
		q->front = q->front->next;

		if(q->front == NULL){
			q->rear = NULL;
		}

		return temp;
	}


	int main(void){
		node * Qnode = NULL;
		queue * Q = create_queue();
		enqueue(Q,5);
		enqueue(Q,17);
		Qnode = dequeue(Q);
				if(Qnode != NULL){
					printf("dequeued data is %d\n", Qnode->key);
				}

		enqueue(Q,1);
		Qnode = dequeue(Q);
				if(Qnode != NULL){
					printf("dequeued data is %d\n", Qnode->key);
				}

		Qnode = dequeue(Q);
		if(Qnode != NULL){
			printf("dequeued data is %d\n", Qnode->key);
		}
		return 0;
	}


