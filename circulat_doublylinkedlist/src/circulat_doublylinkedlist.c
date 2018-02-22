/*
 ============================================================================
 Name        : circulat_doublylinkedlist.c
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
	struct node * previous;
}node;


node * createnode(int value);
node * createlist(node *newnode, node* last);
node *addTobegin(node *newnode, node* last);
node *addToend(node *newnode, node** last);
node *addinmiddle(node *newnode, node* last, int value);
void display(node * last);

int main(void) {
	node * LAST = NULL;
	LAST = createlist(createnode(23),LAST);
	addToend(createnode(32),&LAST);
	addToend(createnode(45),&LAST);
	addToend(createnode(12),&LAST);
	addTobegin(createnode(18),LAST);
	addinmiddle(createnode(56),LAST,45);
	addToend(createnode(76),&LAST);
	display(LAST);
	return EXIT_SUCCESS;
}

node * createnode(int value){
	node * temp= NULL;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;
	temp->previous = NULL;
	return temp;
}

node * createlist(node *newnode, node* last){

	if(last == NULL){
		last = newnode;
		last ->next = last;
		last->previous = last;
	}
	return last;
}

node *addTobegin(node *newnode, node* last){
	newnode->next = last->next;
	last->next = newnode;
	newnode->previous = last;
return last;
}


node *addToend(node *newnode, node**last){
	node *l = *last;
	newnode->next = l->next;
	l->next = newnode;
	l = newnode;
	newnode->previous = *last;
	*last = l;
return *last;
}

node *addinmiddle(node *newnode, node* last, int value){ // newnode is to be inserted after the node containing value
	node *prevnode = last;
	node *nextnode = last->next;

	while(prevnode->data != value){
		prevnode = prevnode->next;
		nextnode = nextnode->next;
		}
	prevnode->next = newnode;
	newnode->previous = prevnode;
	newnode->next = nextnode;
	return last;

}

void display(node * last){
	node *p = last;
	printf("%d->",p->next->data);
	while(p->next != last){
		p = p->next;
		printf("%d->",p->next->data);
		}

}
