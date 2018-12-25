#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int total = 0;
void *func(void* val)
{
	int v = (int) val;
	total = total + (v*v);
}
int main()
{
	int n;
	printf("Enter the value of N\n");
	scanf("%d",&n);
	pthread_t t[n];
	int i;
	for(i=0;i*i<=n;i++)
	{
		pthread_create(&t[i],NULL,func,(void*)i);
	}
	for(i=0;i*i<=n;i++)
	{
		pthread_join(t[i],NULL);
	}
	printf("Sum of the series is :: %d\n",total);
	return 0;
}
