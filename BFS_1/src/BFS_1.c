/*
 ============================================================================
 Name        : BFS_1.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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
		int key;
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

	void enqueue(queue *q, t_node * k,t_node *root){
		k = insert(create_tree(k),root);

		if(q->rear == NULL){
			q->front = q->rear = k;
		}

		q->rear->next = k;
		q->rear = k;
	}


	t_node *dequeue(queue *q){
		if(q->front == NULL){
			return NULL;
		}

		t_node * temp = q->front;
		q->front = q->front->next;

		if(q->front == NULL){
			q->rear = NULL;
		}

		return temp;
	}

	void BFS(t_node * root, queue *q){
			if(root == NULL){
				return;
			}
			t_node * d;
			printf("########################\n");
			/*d = dequeue(q);
			printf("%d->",d->data);*/
			printf("%d->",root->data);

			if(root->left != NULL){
				enqueue(q,create_tree(root->left),root);
			}
			if(root->right != NULL){
				enqueue(q,create_tree(root->right),root);
			}

			d = dequeue(q);

			BFS(d, q);


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
		while(root != NULL){
		enqueue(q,create_tree(root),root);
		//enqueue(q,create_tree(46),root);
		printf("%d\n",q->data);
		root = root->left;
		}
		//BFS(root,q);
		return 0;
	}




