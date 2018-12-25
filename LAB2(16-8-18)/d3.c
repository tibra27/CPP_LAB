# include <stdio.h>
# include<stdlib.h>
# include <pthread.h>
# include<limits.h>
int *inp;
int n,c;
int max=INT_MIN;
int min=INT_MAX;
pthread_mutex_t flag=PTHREAD_MUTEX_INITIALIZER;
void *sum(void *x)
{
    for(c=0;c<n;c=c+2)
    {
        pthread_mutex_lock(&flag);
        if(max<inp[c])
        {
        	max=inp[c];
	}
	if(min>inp[c])
	{
		min=inp[c];
	}
        pthread_mutex_unlock(&flag);
    }
    pthread_exit(NULL);    
}
main()
{
    int i;
    pthread_t t;
    printf("Enter Number of elements in array:");
    scanf("%d",&n); 
    inp=(int *)malloc(sizeof(int)*n); 
    for(i=0;i<n;i++)
    {
    	scanf("%d",&inp[i]);
    } 	  
    pthread_create(&t,NULL,sum,(void *)inp);
    for(c=1;c<n;c=c+2)
    {
        pthread_mutex_lock(&flag);
        if(max<inp[c])
        {
        	max=inp[c];
	}
	if(min>inp[c])
	{
		min=inp[c];
	}
        pthread_mutex_unlock(&flag);
    }
    pthread_join(t,NULL);
    printf("minimum element is=%d\nmaximum element is=%d\n",min,max);
    return 0;
}


