
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

typedef struct dictionary{
	char *key;
	char *mean;
}dictionary_t;

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

void insert(trie_t * root, const char *key, const char *mean){

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

char* modify(trie_t * root, const char *key){
	int level;
	int length = strlen(key);
	int index;
	char *str;
	trie_t * pcrawl = root;

	for(int level =0; level<length;level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pcrawl->trie_array[index]){
		return NULL;
		}

		pcrawl = pcrawl->trie_array[index];

	}
	if(pcrawl->end_of_word){
		printf("enter the meaning to be modified\n");
		scanf("%s",&str);
		pcrawl->meaning = (char*)malloc(sizeof(str));
		strcpy(pcrawl->meaning,&str);
		return pcrawl->meaning;
	}
	return NULL;
}

bool isEmpty(trie_t *root){

	for(int i=0;i<ALPHABET_SIZE;i++)
		if(root->trie_array[i])
			return false;
	return true;

}

trie_t *delete(trie_t *root,const char *key,int level){

	if(!root) return NULL;

	if(level == strlen(key)){
		if(root->end_of_word)	root->end_of_word = false;

		if(isEmpty(root)){
			free(root);
			root = NULL;
		}

		return root;
	}

	int index = CHAR_TO_INDEX(key[level]);
	root->trie_array[index] = delete(root->trie_array[index],key,level+1);

	if(isEmpty(root)){
		free(root);
		root = NULL;
	}

	return root;
}

void file_handle_arr12( dictionary_t  dictionaries[]){
	static const char filename[] = "words.txt";
	FILE *file = fopen ( filename, "r" );
	int ch,lines=0;
	do
	{
		ch = fgetc(file);
		if (ch == '\n')
			lines++;
	} while (ch != EOF);

	rewind(file);

	char *contents[lines];
	int i = 0;
	size_t len = 0;
	for(i = 0; i < lines; i++)
	{
		contents[i] = NULL;
		len = 0;
		getline(&contents[i], &len, file);
	}
	for(i = 0; i < lines; i++)
	{// for each line from the file
		char *ch;
		//split by tab
		ch = strtok(contents[i], "\t");//will return first token of the first word split by tab
		int k=0;
		while (ch != NULL) {
			if(k==0){
				// to get actual word
				dictionaries[i].key=ch;
			}else{
				// to get meaning in the second iteration
				dictionaries[i].mean=ch;
			}
			k++;
			ch = strtok(NULL, "\n");//
		}
	}
	fclose(file);
}



int main(void){
	dictionary_t dictionaries[456];
	trie_t * root = create_node();
	char *str;
	char *str1;
	char *str2;
	file_handle_arr12(&dictionaries);
	for(int i =0;i<455;i++){
		insert(root,dictionaries[i].key,dictionaries[i].mean);
	}


	printf("enter key to search meaning");
	scanf("%s",&str);
	printf("%s\n",search(root,&str));

	printf("%s ------%s\n", "quake", search(root,"quake") );
	printf("%s ------%s\n", "inflow", search(root,"inflow") );
	printf("%s ------%s\n", "deserted", search(root,"deserted") );

	printf("enter key to delete\n");
	scanf("%s",&str2);
	root = delete(root,&str2,0);

	printf("%s ------%s\n", "quake", search(root,"quake") );
	printf("%s ------%s\n", "inflow", search(root,"inflow") );
	printf("%s ------%s\n", "deserted", search(root,"deserted") );

	printf("enter key to modify meaning");
	scanf("%s",&str1);
	printf("%s\n",modify(root,&str1));

	printf("%s ------%s\n", "quake", search(root,"quake") );
	printf("%s ------%s\n", "inflow", search(root,"inflow") );
	printf("%s ------%s\n", "deserted", search(root,"deserted") );

	return 0;
}

