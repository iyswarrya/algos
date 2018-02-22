/*
 ============================================================================
 Name        : linkedlist.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} node;

node * create(int n);
void display(node * head);
void delete_node(node *head, int position);
void insert_node(node *head, int position);
int count(node * head);
int searching(node * head, int value);
//node *  reverse(node * head);
void  reverse(node ** head);
int midpoint(node * head);
int midpoint_val(node * head,int count);
int binary_sort(node *head, int value);

int main(void) {
	struct node *HEAD = NULL;
	int n=0;
	int mid_point_val, mid_point;
	printf("enter no of nodes :\n");
	scanf("%d",&n);
	HEAD= create(n);
	display(HEAD);
	//delete_node(HEAD,3);
	//printf("\n\n After deletion\n\n");
	//display(HEAD);
	//insert_node(HEAD,3);
	//printf("\n\n After insertion\n\n");
	//display(HEAD);
	//printf("\n\n No of nodes: \n\n");
	//count(HEAD);
	//printf("%d\n",count(HEAD));
	//searching(HEAD,65);
	//printf("start reversing\n");

	//reverse(&HEAD);
	//printf("done reversing\n");
	//display(HEAD);

	mid_point = midpoint(HEAD);
	printf("\n midpoint is %d\n",mid_point);
	mid_point_val = midpoint_val(HEAD,midpoint);
	printf("\n midpoint value is %d\n",mid_point_val);
	binary_sort(HEAD,2);
	//printf("\n midpoint is %d\n",binary_sort(HEAD, 4));

	return 0;
}

node * create(int n) // create method which gets number of nodes n from user.
{
	node *head= NULL;
	node *p= NULL;
	node *temp= NULL;
	for(int i=0 ; i<n; i++) {
		temp = (node*)malloc(sizeof(node));
		printf("enter the data for node %d:\n", i+1);
		scanf("%d",&(temp->data));
		temp->next= NULL;
		if(head == NULL) // head is NULL only during 1st iteration, since we initialized head to null; head node is created //
			head = temp;
		else {
			p = head;
			while (p->next != NULL)
			{
				p= p->next; //this loop gets executed from the third iteration until it reaches n.
			} p->next = temp; // second node is created
		}
	}
	return head;
}

void display(node * head){
	node * p = head;

	while (1)//if using p->next, the last element will not be printed.{
	{printf("%d->",p->data);
	if(p->next == NULL){
		break;
	}
	p=p-> next;
	}
}


void delete_node(node *head, int position){
	node *p, *q;
	p=q=head;
	for(int i=1;i<position-1;i++){

		p = p-> next;
	} q = p->next;
	p->next = q->next;
	free(q);
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

	p->next = temp; //making p->next point to the temp node
	temp->next = q; // making temp->next point to the q node

}


int count(node * head){
	node * p= head;
	int result = 1;
	if(p->next != NULL){
		result = result + count(p->next);
	}
	return result;
}

int searching(node * head, int value) {
	//node * p = head;

	if(head->data == value){
		printf("data found\n");
	}
	if(head->next != NULL) {
		searching(head->next, value);
	}
	return 0;

}


//node * reverse(node * p){
//	node * nextNode=NULL;
//	node * prevNode=NULL;
//	node * currentNode = p;
//	while(currentNode != NULL){
//		nextNode = currentNode->next;
//		currentNode->next = prevNode;
//		prevNode=currentNode;
//		currentNode=nextNode;
//	}
//	p= prevNode;
//	return p;
//	//display(p);
//	printf("***************\n");
////	node * temp =NULL;
////	for (int i =0;i<n)
////	temp
////	return 0;
//}

void reverse(node ** p){
	node * nextNode=NULL;
	node * prevNode=NULL;
	node * currentNode = *p;
	while(currentNode != NULL){
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode=currentNode;
		currentNode=nextNode;
		//		printf("%d^^^^^^^^^^%d\n",(prevNode== NULL || prevNode->data)==NULL?0:prevNode->data,
		//				(currentNode==NULL || currentNode->data==NULL)?0:currentNode->data);
	}
	printf("***********************++++++++++++++++\n");
	printf("%d\n",*(*p));

	*p= prevNode;
	printf("#####################\n");
	printf("%d\n",*(*p));
	printf("***************\n");
}


int midpoint(node * startNode, int endPosition){
	node *p=startNode;
	int count =1;
	if((p->next== NULL || p->next->next == NULL || count > endPosition/2)){
		//printf("\n%d\n",p->data);
		return count;

	}

	return count = count+midpoint(p->next->next);
	printf("\n midpoint is %d\n",count);
}


int midpoint_val(node * head,int count){
	node *p= head;
	count = midpoint(p);
	for(int i=1;i<count-1;i++){
			p=p->next;
		}p=p->next;
		int midpoint_val = p->data;
		printf("\n the midpoint value is %d\n",midpoint_val);
		return midpoint_val;
}


int binary_sort(node *head, int value){
	node *p=head;
	int mid_point_val;
	int mid_point;
	mid_point = midpoint(p);
	mid_point_val = midpoint_val(p,mid_point);

	if(value < mid_point_val){

	}
	return 0;
}

