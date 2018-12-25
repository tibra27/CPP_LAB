#include<stdio.h>
#include<pthread.h>
void * fun(void *a)         //function to be run when thread is created.
{
	char *b;
	b=(char *)a;
	printf("%s",b);
}
int main()
{
	char *msg="hello world\n";
	pthread_t t1;      //create a thread id
	pthread_create(&t1,NULL,fun,msg);    //create thread
	pthread_join(t1,NULL);   //for holding the main fun. so that before execution of thred,the main fun. can not be exit.
	return 0;
}
