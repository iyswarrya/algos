/*
 ============================================================================
 Name        : queue.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

typedef struct cell {
	int data;
	struct node * next;
} cell;

cell * create(int n) // create method which gets number of nodes n from user.
{
	cell *head= NULL;
	cell *p= NULL;
	cell *temp= NULL;
	for(int i=0 ; i<n; i++) {
		temp = (cell*)malloc(sizeof(cell));
		printf("enter the data for cell %d:\n", i+1);
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



/* A utility function to insert a new node with given key in BST */
 node* insert( node * nodetobeinserted, node* node)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return nodetobeinserted;

	/* Otherwise, recur down the tree */
	if (nodetobeinserted->data < node->data)
		node->left = insert(nodetobeinserted, node->left);
	else if (nodetobeinserted->data > node->data)
		node->right = insert(nodetobeinserted, node->right);

	/* return the (unchanged) node pointer */
	return node;
}

 void traversal ( node* node)
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

 void preorder(node * parentNode){
	 if(parentNode != NULL){
		 printf("%d->",parentNode->data);
	 }

	 if(parentNode->left != NULL){
		 preorder(parentNode->left);
	 }

	 if(parentNode->right != NULL){
	 		 preorder(parentNode->right);
	 	 }
 }

 void postorder(node * parentNode){
	 if(parentNode->left != NULL){
		 postorder(parentNode->left);
	 }
	 if(parentNode ->right != NULL){
		 postorder(parentNode->right);
	 }
	 printf("%d->",parentNode->data);


 }

/* A utility function to insert a new node with given key in BST */
 void search( node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) {
		printf("not found\n");
		return;
	}
	if(node->data == key){
		printf("data found\n");
	}
	/* Otherwise, recur down the tree */
	if (key < node->data)
		search(node->left, key);
	else if (key > node->data)
		search(node->right, key);

	/* return the (unchanged) node pointer */
	return;
}

 node * createNode(int data){
	 node* temp = ( node *) malloc( sizeof( node) );

	     temp->data = data;
	     temp->left = temp->right = NULL;

	     return temp;
 }

/* Driver program to test above functions*/
int main()
{
	node *root = NULL;
	root = insert(createNode(50), root);
	insert(createNode(30), root);
	insert(createNode(60), root);
	insert(createNode(15), root);
	insert(createNode(40), root);
	insert(createNode(62), root);
	insert(createNode(2), root);
	insert(createNode(61), root);
	insert(createNode(72), root);
	insert(createNode(100), root);

	search(root, 61);
	search(root, 100);
	search(root, 2);
	search(root, 50);
	search(root, 1);

	printf("\nPreorder traversal of binary tree is \n");
	preorder(root);

	printf("\nInorder traversal of binary tree is \n");
	traversal(root);

	printf("\nPostorder traversal of binary tree is \n");
	postorder(root);
//	printf("\nPostorder traversal of binary tree is \n");
//	printPostorder(root);

	getchar();
	return 0;
}
