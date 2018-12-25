#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
pthread_mutex_t flag=PTHREAD_MUTEX_INITIALIZER;
int ch;
int count=0;
struct node
{
	int info;
	struct node *link;
};
struct node* START=NULL;
struct node* create_node()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return n;
}
void insert_node()
{
	struct node *temp,*t;
	temp=create_node();
	count++;///important   used in insert mid and delete
	printf("enter an element to insert");
	scanf("%d",&temp->info);
	temp->link=NULL;
	if (NULL==START)
	{
		START=temp;
	}
	else
	{
		t=START;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
	}
	printf("%d is inserted\n",temp->info);
}
void first_delet()
{
	struct node *r;
	if(NULL==START)
	{
		printf("list is empty");
	}
	else
	{
		r=START;
		START=START->link;
		count=count-1;
		printf("deleted element is:%d\n",r->info);
		free(r);
	}
}
int search(int value)
{
 	struct node* curr = START;
 	while(curr != NULL)
	{
		if(curr->info==value)
		    return 1;
  		curr= curr->link;
 	}
 	return 0;
}
void * fun(void *x)         //function to be run when thread is created.
{
	if(ch==1)
	{
		pthread_mutex_lock(&flag);
		insert_node();
		pthread_mutex_unlock(&flag);
	}	
	if(ch==2)
	{
		pthread_mutex_lock(&flag);
		first_delet();
		pthread_mutex_unlock(&flag);
	}	
	if(ch==3)
	{
		pthread_mutex_lock(&flag);
		int x;
		printf("enter the value to be search\n");
		scanf("%d",&x);
		if(search(x)==1)
		{
			printf("%d is present in list\n",x);
		}
		else
		{
			printf("%d is not present in list\n",x);
		}
		pthread_mutex_unlock(&flag);
	}
	return NULL;
}
int main()
{
	pthread_t t;
	while(1)
	{
		printf("1 for insert\n2 for delete\n3 for search\n4 for exit\n");
		scanf("%d",&ch);
		if(ch<=3)
		{
			pthread_create(&t,NULL,&fun,NULL);
		}
		sleep(5);
		if(ch==4)
		{
			break;
		}	
	}
	pthread_join(t,NULL);
	return 0;
}
