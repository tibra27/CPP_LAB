//-lpthread -lrt
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>
sem_t s;
void* thread(void* arg) 
{ 
	int x=(int)arg;
	while(1)
	{
		sem_wait(&s); 
		printf("\nTHREAD %d:Entered critical section",x); 
  
		sleep(2); 
	  
		printf("\nTHREAD %d:Exiting critical section\n",x); 
		sem_post(&s); 
	}    
} 
int main() 
{ 
	sem_init(&s,0,1); 
	pthread_t t[10];
	int i=0;
	for(i=0;i<10;i++)
	{
		pthread_create(&t[i],NULL,thread,(void *)i); 
		sleep(2);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(t[i],NULL);        
	}    
	sem_destroy(&s); 
	return 0; 
}
