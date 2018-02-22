/*
 ============================================================================
 Name        : dictionary.c
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

//void insert(trie_t * root, const char*key, const char*mean){
void insert(trie_t * root, const char *key, const char *mean){
	printf("#######\\\\\\\\\\");
	int level;
	int length = strlen(key);
	int index;
	trie_t * pcrawl = root;

	for(int level =0; level<length;level++){
		printf("#######");
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

void file_handle(dictionary_t *dictionaries, char *key_1, char *output_1){
	int num=0;
	FILE *fptr;
	fptr = fopen("word.txt","r");
	ssize_t read;
	char *line = 0;
	size_t len = 0;
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	int i =0;
		while ((read = getline(&line, &len, fptr)) != -1) {
		dictionaries = (dictionary_t*) malloc(10*sizeof(dictionary_t));
		char *token = strtok(line, "\t");
		char *token1 = strtok(NULL, "\t");
		strcpy(&(dictionaries+i)->key , &token);
		strcpy(&(dictionaries+i)->mean , &token1);
		strcpy(key_1+i ,(dictionaries+i)->key);
		strcpy(output_1+i ,(dictionaries+i)->mean);
		printf("%s\n",key_1+i);
		//printf("%s", output_1+i);
		//printf("-----------------------------------------\n");
		i++;
		//printf("!!!!!!!!!!!");
	}
	printf("!!!!!!!!!!!");
	//printf("%s\n",key_1+1);
	fprintf(fptr,"%d",num);
	fclose(fptr);

	return;
}



int main(void){
	dictionary_t dictionaries[200];
	trie_t * root = create_node();
	char key_1[200][8];
	char output_1[200][32];

	printf("***********************************\n");
	file_handle(dictionaries,key_1,output_1);
	//printf("%s\n",key_1[1]);
	printf("***********************************\n");
	/*for(int i =0;i<100;i++){
		insert(root,key_1,output_1);
		}*/
	printf("//////////////\n");
	for(int i =0;i<10;i++){
			printf("word:%s\t meaning:%s\n",(dictionaries+i)->key,(dictionaries+i)->mean);
	}

//	for(int i =0;i<10;i++){
//		printf("%s ------%s\n", dictionaries->key, search(root,dictionaries->key) );
//		}

	return 0;
}

