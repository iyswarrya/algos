
/*
 ============================================================================
 Name        : hash_table_list.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct keyValue{
	char * key;
	char * value;
	struct keyValue *next;
}keyvalue;

typedef struct hash_map{
	int size;
	keyvalue ** valueArray;
}hash_map;


hash_map * create_hashmap(int size){
	//printf("%d", size);
	hash_map * hashmap= NULL;
	hashmap = malloc(sizeof(hash_map));
	hashmap->size = size;
	hashmap->valueArray = malloc(sizeof(keyvalue *)* size);

	for(int i = 0; i < size; i++){
		hashmap->valueArray[i] = NULL;
	}

	return hashmap;
}

int hashcode(char *key, int size){
	int hashcode=0;
	//printf("%s\n",key);
	for(int i=0;i<strlen(key);i++){
		//printf("%c\t%d\n",*(key+i),(*(key+i)-'0'));
		hashcode += (*(key+i))*31*i;
	}

	return hashcode % size;
}

hash_map * insert(char *key,char *value,hash_map * hash_map){

	int position = hashcode(key,hash_map->size);


	keyvalue * key_value;
	key_value = malloc(sizeof(struct keyValue));
	key_value->key = key;
	key_value->value = value;
	key_value->next=NULL;

	if(hash_map->valueArray[position] == NULL){
		hash_map->valueArray[position] = key_value;
	}else{

		printf("there's a collision at %d\n",position);
		keyvalue * listNode = hash_map->valueArray[position];
		while(listNode->next != NULL){
			listNode = listNode->next;
		}
		listNode->next = key_value;
	}
	return hash_map;

}

char *find(char *key,hash_map * hash_map){

	int position = hashcode(key,hash_map->size);

	if(hash_map->valueArray[position] == NULL){
		return NULL;
	}else {
		keyvalue * listNode = hash_map->valueArray[position];
		while(listNode != NULL){

			if(strcmp(listNode->key,key) == 0){
				return listNode->value;
			}
			printf("there's a collision at %d\n",position);
			listNode = listNode->next;
		}
		return NULL;
	}

	return hash_map->valueArray[position]->value;

}

void * delete(hash_map * hashmap, char* key){
	int position = hashcode(key,hashmap->size);
	if(hashmap->valueArray[position] == NULL){
		printf("no key value to delete\n");
		return 0;
	}
	if(strcmp(hashmap->valueArray[position]->key, key)==0){
		keyvalue * match_kv = hashmap->valueArray[position];
		hashmap->valueArray[position] = hashmap->valueArray[position]->next;
		free(match_kv);
		return 0;
	}
	else{
		keyvalue * listnode = hashmap->valueArray[position];
		while(listnode->next){

			if(strcmp(listnode->next->key,key)==0){
				keyvalue * match_kv = listnode->next;
				listnode->next = listnode->next->next;
				free(match_kv);
				return 0;
			}
			listnode = listnode->next;
		}
		printf("no key value to delete\n");
	}

	return hashmap;
}

void print(hash_map *hashmap){
	int k=0;
	for(int i=0;i<hashmap->size;i++){
		keyvalue * listNode = hashmap->valueArray[i];
		int p = 0;
		while(listNode != NULL){
			if(p++==0){
				printf("-----------------------------------------------------\n");
				printf("hashcode:%d\n", hashcode(listNode->key,hashmap->size));
			}
			printf("%d=[%s:%s]\t",k++,listNode->key,listNode->value);
			listNode = listNode->next;
		}
		printf("\n");
	}
}



void insertFromFile( hash_map * hash_map){
	static const char filename[] = "words.txt";
	FILE *file = fopen ( filename, "r" );
	int ch,lines=0;
	//read file to know the number of lines
	do
	{
		ch = fgetc(file);
		// since the file content is line based (each word and meaning is a row in the file)
		if (ch == '\n')
			//increment the no of lines when a \n is encountered
			lines++;
	} while (ch != EOF);
	// since the file pointer is moved to the bottom, we need to move back to the start of the file pointer
	rewind(file);
	printf("%d\n",lines);
	char *contents[lines];
	int i = 0;
	size_t len = 0;
	//read all the content line by line in to the string array
	for(i = 0; i < lines; i++)
	{
		contents[i] = NULL;
		len = 0;
		getline(&contents[i], &len, file);
	}
	//close the file - we dont know any more
	fclose(file);


	for(i = 0; i < lines; i++)
	{// for each line from the file
		char *ch;
		//split by tab (the word and the meaning is delimited by a \t)
		ch = strtok(contents[i], "\t");//will return first token of the first word split by tab

		char * key;
		char * value;
		key=ch;
		ch = strtok(NULL, "\n");
		value=ch;

		// call insert in hashmap to enter the key and value
		insert(key, value,hash_map);
	}

}



int main(void) {

	hash_map * hash_map = NULL;
	int size = 455;

	hash_map = create_hashmap(size);


	insertFromFile(hash_map);

	print(hash_map);

//	printf("%d\n",hashcode("abc",hash_map->size));
//	printf("-----------------------------------------------------\n");
//	printf("%d\n",hashcode("abc",hash_map->size));
//	printf("-----------------------------------------------------\n");
//	printf("%d\n",hashcode("abc",hash_map->size));
//	printf("-----------------------------------------------------\n");
//	printf("%d\n",hashcode("abc",hash_map->size));

//	for(int j=0;j<size;j++){
//		if(hash_map->valueArray[j]){
//			printf("position:%d\t%s\t%s \t%d\n",j, hash_map->valueArray[j]->key, hash_map->valueArray[j]->value, hashcode(hash_map->valueArray[j]->key,455));
//		}
//	}
//
//
	printf("#########\n");
	printf("found value: %s  %d\n",find("handsthout",hash_map), hashcode("handsthout",size));
	printf("found value:%s  %d\n",find("previous",hash_map),hashcode("previous",size));
	printf("found value:%s  %d\n",find("quite",hash_map),hashcode("quite",size));
//
	delete(hash_map, "cheesy");
	delete(hash_map, "john");
	printf("------- after deletion--------\n");
	printf("found value:%s\n",find("quake",hash_map));
	printf("found value:%s\n",find("cheesy",hash_map));
	printf("found value:%s\n",find("deserted",hash_map));
	return EXIT_SUCCESS;
}
