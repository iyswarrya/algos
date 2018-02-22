// C program for different tree traversals
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



node *minvalue(node * node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}

int maxdepth(node * node){

	if(node == NULL){
		return 0;
	}
	int ldepth = maxdepth(node->left);
	int rdepth = maxdepth(node->right);

	if(ldepth > rdepth){
		return ldepth+1;
	}
	else
		return rdepth+1;
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
// In order (Left, Root, Right)
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


 //Preorder (Root, Left, Right)
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


 //Post order (Left, Right, Root)
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
 node * search( node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) {
		printf("not found\n");

	}
	printf("current %d\n",node->data);
	if(node->data == key){
				printf("data found\n");
				return node;
			}
	/* Otherwise, recur down the tree */
	if (key < node->data) {
		search(node->left, key);
		}
	else if (key > node->data) {
		search(node->right, key);
	}
	//if(node->data == key){
					//printf("data found\n");

	return node;
	/* return the (unchanged) node pointer */

	}


 node * search_parent( node* root, int key)
 {
 	/* If the tree is empty, return a new node */
 	if (root == NULL) {
 		printf("not found\n");
 	}
 	node * parentNode = root;
 	printf("current parent %d\n",parentNode->data);
 	/* Otherwise, recur down the tree */
 	if (key < root->data) {
 		search_parent(root->left, key);
 	}
 	else if (key > root->data) {
 		search_parent(root->right, key);
 	}

 	if(root->data == key){
 			printf("data found\n");
 		}
 	return parentNode;
 }

 node * createNode(int data){
	 node* temp = ( node *) malloc( sizeof( node) );

	     temp->data = data;
	     temp->left = temp->right = NULL;

	     return temp;
 }

 void delete_node(node *root, int key){

	 node * parentNode = search_parent(root, key);
	 node * nodeTobeDeleted = search(root, key);
	 root = nodeTobeDeleted;

	 /*if(nodeTobeDeleted->left != NULL && nodeTobeDeleted->right == NULL){
		 parentNode->left = nodeTobeDeleted ->left;
	 }
	 else if(nodeTobeDeleted->left != NULL && nodeTobeDeleted->right != NULL){

		 	 while(nodeTobeDeleted->left != NULL){
		 		 nodeTobeDeleted = nodeTobeDeleted->left;
		 	 }
		 	parentNode->right = nodeTobeDeleted;
	 }

	 else if(nodeTobeDeleted->left == NULL && nodeTobeDeleted->right != NULL){

	 }



	 else if(nodeTobeDeleted->left == NULL && nodeTobeDeleted->right == NULL){

	 }*/

	 if(root ->right != NULL) {
		 root = root->right;
		 while(root->left != NULL){
			 root = root->left;
		 }
		 }
	else {
		root = root->left;
		}

	 if(nodeTobeDeleted->data < parentNode->data){
		 parentNode->left = root;
	 }

	 if(nodeTobeDeleted->data > parentNode->data){
	 		 parentNode->right = root;
	 	 }
 }


 node * inorder_successor(node *root, int value){

 	node * temp = search(root,value);


 	if(temp->right != NULL){
 		return minvalue(temp->right);
 	}

 	node * succ = NULL;
 	while(root != NULL){
 		if(temp->data < root->data){
 			succ = root;
 			root = root->left;
 		}
 		else if(temp->data > root->data){
 			root = root->right;
 		}
 		else break;
 	}

 	return succ;
 }
/* Driver program to test above functions*/
int main()
{
	node *root = NULL;
	node *parentNode = NULL;
	node *nodeTobeDeleted = NULL;
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

	/*parentNode = search_parent(root, 61);
	printf("%d\n", parentNode->data);

	nodeTobeDeleted = search(root, 61);
	printf("%d\n", nodeTobeDeleted->data);*

	delete_node(root, 61);


	/*search(root, 100);
	search(root, 2);
	search(root, 50);
	search(root, 1);*/

	printf("\nPreorder traversal of binary tree is \n");
	preorder(root);

	printf("\nInorder traversal of binary tree is \n");
	traversal(root);

	printf("\nPostorder traversal of binary tree is \n");
	postorder(root);
	int depth = maxdepth(root);
	printf("\ndepth %d\n", depth);

	node * temp = inorder_successor(root, 30);
	printf("\ninorder successor %d\n", temp->data);
	//getchar();
//	printf("\nPostorder traversal of binary tree is \n");
//	printPostorder(root);



	return 0;
}
