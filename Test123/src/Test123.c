#include <stdio.h>
#include <stdlib.h>

/*#define N 6
#define INVALID -999
int top=-1;
int stack[N];

void push(int *stack, int value){
	if(top == N-1){
		printf("stack full\n");
		return;
	}

 *(stack+(++top)) = value;

	return;
}


int pop(int *stack){
	int pop_value;

	if(top == -1){
		printf("stack empty\n");
		return NULL;
	}

	pop_value = *(stack+top);
	//option to reset the value to zero
 *(stack+top) = NULL;

	top --;

	return pop_value;
}

int main(){
	push(stack,3);
	push(stack,5);
	push(stack,1);
	push(stack,30);
	//printf("top:%d\n",top);
	//printf("top:%d\n",top);
	printf("popped value: %d\n\n\n", pop(stack));
	push(stack,10);
	push(stack,20);
	push(stack,2);
	push(stack,21);
	printf("popped value: %d\n\n\n", pop(stack));
	push(stack,19);
	printf("top:%d\n",top);
	for(int i = top;i >= 0;i--){
		printf("%d\n",*(stack+i));
	}
	return 0;
}*/

#define N 4

int front = -1;
int rear = -1;
int queue[N];

void enqueue(int * queue, int value){
	//
	if((rear == N-1 && front ==0) || (rear<front && front-rear==1)){
		printf("Queue full\n");
		return;
	}

	if(rear != N-1 && front <= rear ){
		if(rear == -1 && front ==-1){
			front = rear =0;
			*(queue+front)= value;
		}
		else{
			*(queue+(++rear)) = value;
		}
	}

	if(rear == N-1 && front !=0){
		rear = -1;
		rear++;
		*(queue+rear) = value;
	}
}


int dequeue(int *queue){
	int dequeued_value;

	if((rear == -1 && front ==-1) || (front>rear &&  front!= N-1)){
		printf("Queue empty\n");
		return NULL;
	}

	if(front == N-1){
		dequeued_value = *(queue+front);
		*(queue+front) = NULL;
		front = 0;
		return dequeued_value;
	}
	else{
		dequeued_value = *(queue+front);
		*(queue+front) = NULL;
		front++;
		return dequeued_value;
	}
}

int main(){
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
	if(rear >=front){
	for(int i = front;i < N;i++){
		printf("%d\n",*(queue+i));
	}
	}
	else{
		for(int j = front;j < N;j++){
				printf("%d\n",*(queue+j));
		}
		for(int k = 0;k <= rear;k++){
					printf("%d\n",*(queue+k));
				}
	}
	return 0;
}
