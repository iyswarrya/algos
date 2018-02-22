/*
 ============================================================================
 Name        : test_linkedlist.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * next;
	}node;

node * create(node *head, int value);
void deleteNode(node **head, int valueToBeDeleted);
void display(node *head);

int main(void) {
	struct node *HEAD = NULL;
	HEAD = create(HEAD,3);
	create(HEAD,3);
	create(HEAD,2);
	create(HEAD,3);
	create(HEAD,5);
	create(HEAD,3);
	display(HEAD);
	deleteNode(&HEAD,3);
	printf("\n");
	display(HEAD);
	return 0;
}

node * create(node * head,int value){
	node * temp;
	node * currentNode = NULL;

	temp = (node *) malloc (sizeof(node));
	temp->data = value;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		return head;
	}

	currentNode = head;
	while(currentNode->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next = temp;

	return head;
}

void deleteNode(node ** head, int valueToBeDeleted){

	node * p = *head;
	if(p == NULL){
		printf("No node found\n");
		return;
	}

	while(p->data == valueToBeDeleted){  //if value to be deleted is in head
		p = p->next;
		//printf("head value %d\n",p->data);
	}

	*head = p;  //updating head pointer

	node * currentNode = p;
	//printf("currentNode value %d\n",currentNode->data);
	node * nextNode = p;
	//printf("nextNode %d\n",nextNode->data);

	while(currentNode != NULL){
		nextNode = currentNode ->next;  // making nextNode as the next of currentNode
		if(currentNode->next != NULL && currentNode->next->data == valueToBeDeleted){
			currentNode->next = nextNode->next;			//deleting the node
		}
		currentNode = currentNode->next;			//now currentNode and nextNode will point to the same node.
	}

	return;
}

void display(node *head){
	node * currentNode = head;

	if(head == NULL){
		printf("no list found\n");
		return;
	}

	while(currentNode != NULL){
		printf("%d->",currentNode->data);
		currentNode = currentNode->next;
	}
	return;
}

