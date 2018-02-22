/*
 ============================================================================
 Name        : trie.c
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

typedef struct trie{
	struct trie * trie_array[ALPHABET_SIZE];
	bool end_of_word;
}trie_t;

trie_t *create_node(){
	trie_t * node = NULL;

	node = (trie_t*)malloc(sizeof(trie_t));

	for(int i=0;i<ALPHABET_SIZE;i++){
		node->trie_array[i]= NULL;
	}

	node->end_of_word = false;

	return node;

}

void insert(trie_t * root, const char*key){
	printf("####");
	int level;
	int length = strlen(key);
	int index;
	trie_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
			pcrawl->trie_array[index] = create_node();
		}
		pcrawl = pcrawl->trie_array[index];
	}
	pcrawl->end_of_word = true;
}

bool search(trie_t * root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	trie_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
		return false;
		}

		pcrawl = pcrawl->trie_array[index];


	}
	return (pcrawl->end_of_word);

}



int main(void) {

	char key[][8] = {"hello","how","horse", "abba","sister"};
	char output[][32] = {"not present in trie","present in trie"};

	trie_t * root = create_node();

	for(int i =0;i<ARRAY_SIZE(key);i++){
		insert(root,key[i]);
	}


	printf("%s ------%s\n", "how", output[search(root,"how")] );
	printf("%s ------%s\n", "horse", output[search(root,"horse")] );
	printf("%s ------%s\n", "abs", output[search(root,"abs")] );
	printf("%s ------%s\n", "abba", output[search(root,"abba")] );

	//delete(root, "how");



	return 0;
}
