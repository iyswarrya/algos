/*
 ============================================================================
 Name        : dictionary1.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


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
#include <string.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')   // if alphabet 'n' is stored in c, then it gives the distance between a and n
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])



typedef struct trie{
	struct trie * trie_array[ALPHABET_SIZE];
	char *meaning;
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

void insert(trie_t * root, const char*key, const char*mean){

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
	pcrawl->meaning = (char*)malloc(sizeof(mean));
	strcpy(pcrawl->meaning, mean);
}

char* search(trie_t * root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	trie_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
		return NULL;
		}

		pcrawl = pcrawl->trie_array[index];

	}
	if(pcrawl->end_of_word){
		return pcrawl->meaning;
	}
	return NULL;
}




int main(void) {
	//dictionary_t * dictionaries;
char key[][8] = {"hello","doing","horse", "abba","sister"};
char output[][32] = {"hi","working", "domestic animal","music album","sibling"};
trie_t * root = create_node();
for(int i =0;i<ARRAY_SIZE(key);i++){
		insert(root,key[i],output[i]);
}

printf("%s ------%s\n", "hello", search(root,"hello") );
printf("%s ------%s\n", "horse", search(root,"horse"));
printf("%s ------%s\n", "abs", search(root,"abs") );
printf("%s ------%s\n", "abba", search(root,"abba"));

	return 0;
}
