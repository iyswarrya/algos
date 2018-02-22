/*
 ============================================================================
 Name        : LL_delete.c
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



node * create(node *head,int value);

void deleteNode(node *head,int value);

void display(node *head);



int main(void) {

    struct node *HEAD = NULL;

    HEAD = create(HEAD,7);

    create(HEAD,1);

    create(HEAD,7);

    create(HEAD,10);

    create(HEAD,7);

    create(HEAD,11);

    display(HEAD);

    deleteNode(HEAD,7);
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



void deleteNode(node * head,int value){

    if(head == NULL){

        printf("No node found\n");

        return;

    }

    if(head->data == value){

        head = head->next;

    }

    node * currentNode = head;

    node * nextNode = head;


    while(currentNode != NULL){

        nextNode = currentNode ->next;

        if(currentNode->next != NULL && currentNode->next->data == value){

           // printf("%d\n", currentNode->next->data);

            //printf("%d\n", nextNode->next->data);

            currentNode->next = nextNode->next;

            //printf("%d\n", currentNode->next->data);



        }

        currentNode = currentNode->next;

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


