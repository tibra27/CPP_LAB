#include<stdio.h>
#include<pthread.h>
void *fun(void *a)   //the argument must be of type void*
{
	char *b;
	b=(char *)a;
        printf("%s\n",b);
        sleep(10);  //provide gap 
	return(NULL);
}
int main()
{
	pthread_t t1,t2,t3,t4,t5;
	char *m1="thread 1:";
	char *m2="thread 2:";
	char *m3="thread 3:";
	char *m4="thread 4:";
	char *m5="thread 5:";
	pthread_create(&t1,NULL,fun,(void *)m1);  //cast argumnt to void*
	printf(" THREAD1 CREATED::YOU ARE IN MAIN FUNCTION\n");
	pthread_create(&t2,NULL,fun,(void *)m2);
	pthread_create(&t3,NULL,fun,(void *)m3);     //cast argumnt to void*
	printf(" THREAD3 CREATED::YOU ARE IN MAIN FUNCTION\n");
	pthread_create(&t4,NULL,fun,(void *)m4);
	pthread_create(&t5,NULL,fun,(void *)m5);     //cast argumnt to void*
	printf(" ALL THREADS CREATED::YOU ARE IN MAIN FUNCTION\n");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	printf("WORK IS COMPLETED\n");
	return 0;
}
