# include <stdio.h>
# include <pthread.h>
int Total=0;
pthread_mutex_t flag=PTHREAD_MUTEX_INITIALIZER;
void *sum(void *x)
{
    int *i,c;
    i=(int*)x;
    
    for(c=2;c<=*i;c=c+2)
    {
        pthread_mutex_lock(&flag);
        Total=Total+ c;
        pthread_mutex_unlock(&flag);
    }
    pthread_exit(NULL);    
}
main()
{
    int n,c;
    pthread_t t;
    printf("Enter Number:");
    scanf("%d",&n);    
    pthread_create(&t,NULL,sum,(void *)&n);
    for(c=1;c<=n;c=c+2)
    {
        pthread_mutex_lock(&flag);
        Total=Total+c;
        pthread_mutex_unlock(&flag);
    }
    pthread_join(t,NULL);
    printf("Sum is : %d \n",Total);
}


