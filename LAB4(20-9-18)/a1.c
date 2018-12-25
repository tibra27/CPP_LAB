//-lpthread -lrt
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
sem_t s; 
void* thread(void* arg) 
{ 
	char* msg=(char*)arg;
	while(1)
	{
		//wait 
		sem_wait(&s); 
		//printf("\n%s",msg);
		printf("\n%s:Entered critical section",msg); 
		//critical section 
		sleep(2); 
		//signal 
		printf("\n%s:Exiting critical section\n",msg); 
		sem_post(&s); 
	}    
} 

int main() 
{ 
	sem_init(&s,0,1); 
	pthread_t t1,t2; 
	char* m1="this is thread1";
	char* m2="this is thread2";
	pthread_create(&t1,NULL,thread,(void *)m1); 
	sleep(2); 
	pthread_create(&t2,NULL,thread,(void *)m2); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&s); 
	return 0; 
}

