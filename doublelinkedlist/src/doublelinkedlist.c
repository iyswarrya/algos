/*
 ============================================================================
 Name        : doublelinkedlist.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *previous;
} node;

node * create(int n);
void display(node * head);
void insert_node(node *head, int position);
void delete(int value, node ** head);

int main (void) {
	int n;
	struct node * HEAD = NULL;
	struct node * TAIL = NULL;
	printf("enter no of nodes :\n");
	scanf("%d",&n);
	HEAD= create(n);
	display(HEAD);
	//insert_node(HEAD,1);
	//printf("\n\n After insertion\n\n");
	//display(HEAD);
	printf("\n");
	delete(3, &HEAD);
	printf("\n\n After deletion\n\n");
	display(HEAD);
}

node *create(int n) {
	node *head = NULL;
	node *tail = NULL;
	node *temp = NULL;
	node *p = NULL;
	//node *q = NULL;


	for(int i =0;i<n;i++)	{
		temp = (node*)malloc(sizeof(node));
		printf("Enter the data to be stored in the node %d\n",i+1);
		scanf("%d",&(temp->data));
		temp->next = NULL;


		if(head == NULL) {
			temp->previous = NULL;
			head = temp;
		}
		else {
			p = head;
			while(p->next !=NULL){
				p = p->next;
			}
			temp->previous = p;
			p->next = temp;
			tail= temp;
		}

	}

	return head;
}

void display(node * head){
	node * p = head;
	while (p != NULL)//if using p->next, the last element will not be printed
	{printf("%d->",p->data);
	p=p->next;
	}
}

void insert_node(node *head, int position){
	node *p,*q, *temp; // declaring two pointers for iterating over the list until the position.
	p=q=head; // initializing to head.
	int i=1;

	// creating a temporary node

	temp = (node*)malloc(sizeof(node)); // memory allocation for temp node.
	printf("\n enter the data to be inserted for node %d:\n", position);
	scanf("%d",&(temp->data));
	temp->next= NULL;

	// p iterates till one position before the required position.
	for(i=1; i<position-1; i++ ){
		p= p-> next;
	}
	q= p->next; // q iterates till one position after p.

	//inserting temp node between p and q.
	temp->previous = p;
	temp->next = q; // making temp->next point to the q node
	p->next = temp; //making p->next point to the temp node
	q->previous = temp;


}

void delete(int value, node ** head){
         node *temp = NULL, *delnode = NULL;
         node *currentnode = *head;

         if(currentnode == NULL){
           return;
         }

        while(currentnode->data == value){
           temp = currentnode;
           currentnode = currentnode->next;
           free(temp);
           currentnode->previous = NULL;
           *head = currentnode;
         }

         while(currentnode != NULL){

           if(currentnode->next != NULL && currentnode->next->data == value){
             delnode = currentnode->next;
             if(currentnode->next->next == NULL){
            	 currentnode->next = NULL;
            	 }
             else{
             currentnode->next = currentnode->next->next;
             currentnode->next->previous = currentnode;
             	 }
             free(delnode);
           }

           currentnode = currentnode->next;
         }
         return;
       }

