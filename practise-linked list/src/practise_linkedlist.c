/*
 ============================================================================
 Name        : practise.c
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


node * createNode(node *head);
void display(node * head);
int midpoint(node * head);
int midpoint_val(node *head, int mid_point);
node * reverse(node ** head);
void delete(node * head, int position);
void insert(node * head, int position);
int search (node * head, int value);

int main(void) {

	struct node *HEAD = NULL;
	int mid_point;
	HEAD = createNode(HEAD);
	createNode(HEAD);
	createNode(HEAD);
	createNode(HEAD);
	createNode(HEAD);
	/*createNode(HEAD);
	createNode(HEAD);
	createNode(HEAD);*/
	display(HEAD);
	mid_point = midpoint(HEAD);
	printf("\n midpoint is %d\n",mid_point);
	midpoint_val(HEAD, mid_point);
	//display(HEAD);
	//reverse(&HEAD);
	//display(HEAD);
	delete(HEAD, 3);
	display(HEAD);
	insert(HEAD, 3);
	display(HEAD);
	search(HEAD,4);
}

node * createNode(node *head){
	node * temp;
	node *p = NULL;


	temp = (node *)malloc(sizeof(node));
	printf("enter the value to be inserted: \n");
	scanf("%d",&(temp->data));
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return head;
	}
	else {
		p = head;
		while(p->next !=NULL){
			p=p->next;
		}
		p->next = temp;
	}
	return head;

}

void display(node * head){
	node *p = head;
	printf("%d->",p->data);
	while(p->next != NULL){
		printf("%d->",p->next->data);
		p = p->next;
		}

}

int midpoint(node * head){
	int count=1;
	if (head->next == NULL || head->next->next == NULL ){
		return count;
	}

		return count = count+midpoint(head->next->next);

}

int midpoint_val(node *head, int mid_point){
	for(int i =1; i<mid_point; i++){
		head = head->next;
	}
	printf("midpoint data is %d\n", head->data);
	return head->data;
}

node* reverse(node** head)
{
    node* prev    = NULL;
    node* current = *head;
    node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return *head;
}

void delete(node * head, int position){
		node * p=head;
		/*int count = 1;
	while(head ->next != NULL){
		p = head;
		count = count+1;
		head = head -> next;
		printf("count = %d\n", count);
		if(position == count){
			p->next = head->next;
		}
	}*/
		for(int i=1;i<position-1;i++){
			head = head->next;
		} p = head ->next;
		head->next = p->next;
		free(p);
}


void insert(node * head, int position){
	node *p = head;
	node * temp;
	temp = (node *)malloc(sizeof(node));
	printf("enter data for node\n");
	scanf("%d",&(temp->data));
	temp->next = NULL;

	for(int i=1;i<position-1;i++){
		head = head->next;
	}
		p= head->next;
		head->next = temp;
		temp->next = p;

}

int search (node * head, int value){

	//  * two methods *
	// method 1

	/*int position=1;
	while (head->next != NULL){
		position = position +1;
		head = head->next;

		if(head->data == value){
			printf("data found in position %d\n",position);
			return position;
		}
	}
	printf("data not found\n");
	return 0;*/


	// method 2
	if(head->data == value){
			printf("data found\n");
		}
		if(head->next != NULL) {
			search(head->next, value);
		}
		return 0;

}

