#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct queue								//ONGOING CODE
{
	int data;
	struct queue *next;
};

queue *root;
int size=0;

void dequeue
{
	int result;
	if(size==0)
		return -1;
	if(size==1)
	{
		result=root->data;
		root=NULL;
		size--;
		return result;
	}
	queue *p;
	p=root;
	for(int i=0;i<size-2;i++)
	{
		p=p->next;
	}
	queue *q;
	q=p->next;
	result=p->next->data;
	p->next=NULL;
	size--;
	free(q);
	return result;
	
}


void enqueue(int data)
{
	if(size==0)
	{
		root=(queue*)malloc(sizeof(queue));
		root->data=data;
		root->next=NULL;
		size++;
	}
	else
	{
	
	queue *p=(queue*)malloc(sizeof(queue));
	p->data=data;
	p->next=root;
	root=p;
	size++;
	}
}

