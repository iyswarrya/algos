/*
 ============================================================================
 Name        : que_array.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#define n 20

typedef struct queue{
int front = 0;
int rear = -1;
int data[n];
};

typedef struct t_node
{
	int data;
	struct t_node* left;
	struct t_node* right;
} t_node;

t_node * insert(t_node * nodeTobeInserted, t_node *t_node){
	if(t_node == NULL){
		return nodeTobeInserted;
	}

	if(nodeTobeInserted->data  < t_node ->data){
		t_node->left = insert(nodeTobeInserted, t_node->left);
	}

	else if(nodeTobeInserted->data  > t_node ->data){
		t_node->right = insert(nodeTobeInserted,t_node->right);
	}

	return t_node;
}

t_node * createNode (int key){
	t_node * temp;
	temp = (t_node*)malloc(sizeof(t_node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/*void enqueue(){
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
}*/

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

void BFS (t_node * root){
	printf("%d\n", queue[front]);

	if(front<=rear && root->data == queue[front]){
		//printf("%d\n",queue[front]);
	 if(root->left != NULL){
		 queue[++rear]=root->left->data;
	 }
	 if(root->right != NULL  || root->right == NULL){
		 queue[++rear]=root->right->data;
	 }
	 front++;
	}

	if(root->left != NULL){
		BFS(root->left);
	}
	if(root->right != NULL){
		BFS(root->right);
	}
}



int main(void){
		t_node *root = NULL;
		root = insert(createNode(40),root);
		insert(createNode(46),root);
		insert(createNode(14),root);
		insert(createNode(24),root);
		insert(createNode(35),root);
		insert(createNode(50),root);
		insert(createNode(10),root);
		queue[++rear] = root->data;
		BFS(root);
		display();

return 0;
}
