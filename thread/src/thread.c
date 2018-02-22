/*
 ============================================================================
 Name        : thread.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#define NUM_THREADS 3
void *printfun1(int thread_id);

pthread_mutex_t lock_x;
int main(void){
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&lock_x, NULL);
	for(int i = 0;i<NUM_THREADS; i++){
		int thread_number = (i+1);
		if(pthread_create(&threads[i], NULL, printfun1, thread_number)< 0){
			printf("thread creation failed\n");
		}else{
			printf("thread created\n");
		}
	}
	for(int i = 0;i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}
}

void *printfun1(int thread_id)
{
	pthread_mutex_lock(&lock_x);
    for(int i =0;i<=1000;i++)
    {
        printf("This is thread %d: %d\n", thread_id, i);
    }
    pthread_mutex_unlock(&lock_x);
   return NULL;
}
