#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 100000           
int que[SIZE];               
int front,rear;                
sem_t empty, products;
void *producer(void *arg)        
{
	int value;
	do                         
	{
		int value = rand() % 100;             
		printf("produced products: %d\n", value);
		//sem_wait(&empty);               //wait for empty space in queue      
		que[rear] = value;               
		rear = (rear + 1) % SIZE;
		sem_post(&products);              
		sleep(2);                
	}
	while(value);
	pthread_exit(NULL);      
}
void *consumer(void *arg)            
{
	int value;
	do                         
	{
		sem_wait(&products);       //wait  for some product  in queue
		value = que[front]; 
		front = (front + 1) % SIZE;
		printf("consumed products: %d\n", value);
		//sem_post(&empty); 
		sleep(2); 
	}
	while(value);
	pthread_exit(NULL); 
}
int main(int argc, char *argv[])
{                		
	pthread_t prod_t, cons_t;							
	sem_init(&empty, 0, SIZE);
	sem_init(&products, 0, 0);
	pthread_create(&prod_t, NULL, producer, NULL);
	pthread_create(&cons_t, NULL, consumer, NULL);                          
	pthread_join(prod_t, NULL);
	pthread_join(cons_t, NULL);                       
	sem_destroy(&empty);
	sem_destroy(&products);
	return 0;
}
