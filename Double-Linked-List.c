#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node{
	
	char c;
	struct node *next,*back;
};

typedef struct node node;

node* KayitGir()
{
   int n,k;
    node *head,*p,*q;
    printf("How many students in the list?");
    scanf("%d",&n);
    for(k=0;k<n;k++){
        if(k==0){
            head = (node *)malloc(sizeof(node));
            p = head;
        }
        else{
            p->next = (node *) malloc(sizeof(node));
            p=q;
            p = p->next;
            p->back=q;
        }
        printf("Enter %d. student name: ",k+1);scanf("%c",&p->c);fflush(stdin);
    }
    head->back=NULL;
    p->next = NULL;    
    return head;
}

void Hesapla(node *head)
{
	node *q=head;
	node *p=head;
	int sayac=0;
	int kontrol=1;
	int i;
	while(q->next!=NULL)
	{
		q=q->next;
		sayac++;
	}
	sayac=sayac/2;
	for(i=0;i<sayac;i++)
	{
		if(p->c!=q->c)
		{
			kontrol=0;
			break;
		}
		p=p->next;
		q=q->back;
	}
	if(kontrol==1)
		printf("Ayn�d�r");
	else
		printf("Ayn� deildir.");
}

void showList(node *head)
{
	node *p=head;
	while(p!=NULL)
	{
		printf("%c",p->c);
		p=p->next;
		
	}
	
	
}



int main()
{
	
	
	
	node *head;
	
	int secim,giris;
	do
	{
		printf("1-_Kay�t gir.\n2-_Hesapla\n3-_C�k�s");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				head=KayitGir();
				break;
			case 2:
				Hesapla(head);
				break;
			case 3:
				showList(head);
				break;
			default:
				if(secim!=4)
				printf("Lutfen gecerli bir secenek giriniz.");
			
		}
		
	}while(secim!=3);



	return 0;


}