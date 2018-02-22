/*
 ============================================================================
 Name        : trie_deletion.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')   // if alphabet 'n' is stored in c, then it gives the distance between a and n
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

typedef struct trie_node{
	struct trie_node * trie_array[ALPHABET_SIZE];
	bool end_of_word;
	int value; // non zero if leaf
}trie_node_t;

typedef struct trie{
	trie_node_t *root;
	int count;
}trie_t;

trie_node_t *create_node(){
	trie_node_t * node = NULL;

	node = (trie_node_t*)malloc(sizeof(trie_node_t));

	for(int i=0;i<ALPHABET_SIZE;i++){
		node->trie_array[i]= NULL;
	}

	node->end_of_word = false;

	return node;

}

void initialize(trie_t *pTrie){
	pTrie->root = create_node();
	pTrie->count = 0;
}

void insert(trie_node_t * root, const char*key){
	printf("####");
	int level;
	int length = strlen(key);
	int index;
	trie_node_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
			pcrawl->trie_array[index] = create_node();
		}
		pcrawl = pcrawl->trie_array[index];
	}
	pcrawl->end_of_word = true;
}

bool search(trie_node_t * root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	trie_node_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
		return false;
		}

		pcrawl = pcrawl->trie_array[index];


	}
	return (pcrawl->end_of_word);

}

trie_node_t* search1(trie_node_t * root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	trie_node_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
		return NULL;
		}
		printf("%s\n",pcrawl->trie_array[index]);
		pcrawl = pcrawl->trie_array[index];

	}

	return pcrawl->trie_array[index];
	//if(pcrawl->end_of_word){
		//return pcrawl;
	//}

}

int leafNode(trie_node_t *pNode){
	return (pNode->value != 0);
}

int isItFreeNode(trie_node_t * pNode){
//if a node is not free, it means this part of key is a prefix to some other
	//key. If a node is not free, we translate the trie without doing anything
	for(int i=0;i<ALPHABET_SIZE;i++){
		if(pNode->trie_array[i]){
			return 0;  // have child
		}
		return 1;
	}
}

bool deleteHelper(trie_node_t *pNode, char key[], int level,int len){
	if(pNode){
		if(level == len){ // this condition will be true only for last node
			if(pNode->value){ //if other than last node,
				//any other node is leaf,we should not disturb the trie anymore
				pNode->value = 0; //unmarking the last node
				//If empty node is deleted
				if(isItFreeNode(pNode)){
					return true;
				}
				return false;

			}
		}
		else // recursive case
		{
			int index = CHAR_TO_INDEX(key[level]);

			if(deleteHelper(pNode->trie_array[index],key, level+1,len)){

				//last node marked, delete it
				free(pNode->trie_array[index]);
				pNode->trie_array[index] = NULL;
				//recursively climb up and delete eligible nodes
				return (!leafNode(pNode) && isItFreeNode(pNode));
			}
		}
	}
	return false;
}

void deleteKey(trie_t *pTrie, char key[]){
	int len = strlen(key);

	if(len>0){
		deleteHelper(pTrie->root, key, 0,len);
	}
}

/*int deletion(trie_t ** curr, const char *key){
	if(curr == NULL){
		return 0;
	}
	int level;
	int length = strlen(key);
	int index;
	trie_t * pcrawl = curr;

		for(int level =0; level<length;level++){
			index = CHAR_TO_INDEX(key[level]);

			if(!pcrawl->trie_array[index]){
			return NULL;
			}
			printf("%s\n",pcrawl->trie_array[index]);
			pcrawl = pcrawl->trie_array[index];

		}

		if(havechildren(pcrawl)==0){
			pcrawl = NULL;
		}
		else pcrawl->end_of_word = false;

}*/
/*void delete(trie_t * root, const char *key){
	if(search(root, key)==0){
		printf("does not exist\n");
	return;
	}
	int level;
	int length = strlen(key);
	int index;
	trie_t * parent = search1(root, key);
	trie_t * child  = parent-> trie_array[index];
//	for(level =length-1; level >0; level--){
//		index = CHAR_TO_INDEX(key[level]);
//		trie_t * parent = parent->trie_array[index];
//		trie_t * child  = parent-> trie_array[index];
//
		if(!child){
		parent-> trie_array[index] = NULL;
//			parent-> end_of_word = false;
//			continue;
//		}
//		parent-> end_of_word = false;
//		return;
//
//}
//}*/

int main(void) {

	char key[][8] = {"hello","how","horse", "abba","sister"};
	//char output[][32] = {"not present in trie","present in trie"};

	//trie_node_t * root = create_node();
	trie_t trie;
	initialize(&trie);

	for(int i =0;i<ARRAY_SIZE(key);i++){
		insert(&trie,key[i]);
	}

	//deleteKey(&trie, key[0]);

	printf("%s %s\n","hello", search(&trie, "hello") ? "present in trie" : "not present in trie");
	//printf("%s ------%s\n", "how", output[search(root,"how")] );
	//printf("%s ------%s\n", "horse", output[search(root,"horse")] );
	//printf("%s ------%s\n", "abs", output[search(root,"abs")] );
	//printf("%s ------%s\n", "abba", output[search(root,"abba")] );

	//delete(root, "how");



	return 0;
}
