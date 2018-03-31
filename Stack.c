#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

typedef struct stack stack;


stack *p=NULL;


void push(int data)
{
	if(p==NULL)
	{
		p=(stack*)malloc(sizeof(stack));
		p->next=NULL;
	}
	p->data=data;
	stack *temp=(stack*)malloc(sizeof(stack));
	temp->next=p;
	p=temp;
}



int pop()
{
	if(p->next==NULL)
		return -1;
	int result=p->next->data;
	stack *temp=p;
	p=p->next;
	free(temp);
	return result;
}


void show()
{
	stack *temp;
	temp=p->next;
	while(temp!=NULL)
	{
	printf("%d\n",temp->data);
	temp=temp->next;
	
	}
}


int main(){
	push(10);
	push(20);
	push(30);
	show();
	pop();
	pop();
	pop();
	show();
	
	return 0;
}
