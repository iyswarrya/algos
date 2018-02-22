/*
 ============================================================================
 Name        : BFS.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int data;
	struct t_node* left;
	struct t_node* right;
} t_node;

typedef struct node {
	t_node * tnode;
	struct node * next;
}node;

typedef struct queue {
	int data;
	struct node *rear, *front;
}queue;

t_node *create_tree(int k){
	t_node * temp;
	temp = (t_node*) malloc(sizeof(t_node));

	temp -> data = k;
	temp->left = temp->right = NULL;

	return temp;
}

t_node * insert(t_node * nodeTobeInserted, t_node *t_node ){
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

t_node * create_tnode (int key){
	t_node * temp;
	temp = (t_node*)malloc(sizeof(t_node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node * create_node (t_node * tnode){
	node * temp;
	temp = (node*)malloc(sizeof(node));
	temp->tnode = tnode;
	temp->next = NULL;
	return temp;
}

queue *create_queue(){
	queue * q;
	q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = NULL;
	return q;
}

//void enqueue(queue *q, int k){
//	node * temp = create_node(k);
//
//	if(q->rear == NULL){
//		q->front = q->rear = temp;
//	}
//
//	q->rear->next = temp;
//	q->rear = temp;
//}

void enqueue1(queue *q, t_node *temptnode){
	node * temp = create_node(temptnode);
	//printf("\n%d\n", temptnode->data);
	if(q->rear == NULL){
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

void printQueue(queue * q){
	if(q->front == NULL){
		return;
	}
	node * temp = q->front;
	//printf("%d&&&&&&&&&", q->front->tnode->data);
	while(temp){
		printf("%d->",temp->tnode->data);
		temp=temp->next;
	}
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

void BFS(t_node * root, queue *q){
	//printf("@@@@@@@@@@@@@@@@@@@@@@@@@");
	if(root == NULL){
		return;
	}
	node * d;
	//printf("########################\n");
	//printQueue(q);
	/*d = dequeue(q);
			printf("%d->",d->data);*/
	printf("\n\nDATA=====%d\n\n",root->data);

	if(root->left != NULL){
		enqueue1(q,root->left);
	}
	if(root->right != NULL){
		enqueue1(q,root->right);
	}
	//printf("************************\n");
	//printQueue(q);
	d = dequeue(q);

	BFS(d->tnode, q);


	//			if(root->left != NULL) {
	//			BFS(root->left,q);
	//			}
	//
	//			if(root->right != NULL){
	//			BFS(root->right,q);
	//			}

}

/*void BFS(t_node * root, queue *q){
				t_node * d;

				d = dequeue(q);
				printf("%d->",d->data);

				if(d->left != NULL){
					enqueue(q,d->left->data);
				}
				if(d->right != NULL){
					enqueue(q,d->right->data);
				}

				if(d->left != NULL) {
				BFS(d->left,q);
				}

				if(d->right != NULL){
				BFS(d->right,q);
				}
	}*/

void traversal ( t_node* node)
{
	if (node == NULL)
		return;
	if(node->left != NULL){
		traversal(node->left);
	}
	printf("%d ", node->data);
	if(node->right != NULL){
		traversal(node->right);
	}
}

int main(void){
	t_node * root = NULL;
	queue * q = create_queue();
	root = insert(create_tree(40),root);
	insert(create_tree(46),root);
	insert(create_tree(14),root);
	insert(create_tree(24),root);
	insert(create_tree(35),root);
	insert(create_tree(50),root);
	insert(create_tree(10),root);
	//enqueue(q,root->data);
	printf("-------------IN ORDER TRAVERSAL-------------\n");
	traversal(root);
	//	enqueue1(q,create_tnode(1));
	//	enqueue1(q,create_tnode(10));
	//	enqueue1(q,create_tnode(11));
	//	enqueue1(q,create_tnode(12));
	//	enqueue1(q,create_tnode(13));
	//	printf("Printing queue-------------\n");
	//	printQueue(q);
	printf("\n-----------BFS-------------\n");
	BFS(root,q);
	return 0;
}



