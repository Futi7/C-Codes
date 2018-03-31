#include <stdio.h>
#include <stdlib.h>

struct student{
    int no;
    char name[40];
    int age;
    struct student *next;
};
typedef struct student node;
void showList(node*);

node* deleteNode(node*);
node* deleteSecNode(node*, int);
node* createList(){
    int n,k;
    node *head,*p;
    printf("How many students in the list?");
    scanf("%d",&n);
    for(k=0;k<n;k++){
        if(k==0){
            head = (node *)malloc(sizeof(node));
            p = head;
        }
        else{
            p->next = (node *) malloc(sizeof(node));
            p = p->next;
        }
        printf("Enter %d. student number: ",k+1); scanf("%d",&p->no);
        printf("Enter %d. student name: ",k+1); scanf("%s",p->name);
        printf("Enter %d. student age: ",k+1); scanf("%d",&p->age);
    }
    p->next = NULL;    
    return head;
}

int main(void)
{
    node *head;
    int selection,yas;    
    while(1)
    {
        printf("\n1.Create List\n2.Lab. Solution 3.Show List 4.Delete Second\n5.Exit\n");
        printf("Selection [1-3]?\n");
        scanf("%d",&selection);
        switch(selection)
        {
        case 1: head = createList();
                break;
        case 2: head= deleteNode(head);
                break;
        case 3: showList(head);break;
        case 4: printf("Yasi girin.");scanf("%d",&yas);
                head=deleteSecNode(head,yas);break;
        case 5: exit(0);
        
        }
    }
}
void showList(node *head)
{
    node *p;
    p=head;
    while(p!=NULL)
    {
        printf("Numara::%d\nAd::%s\nYas::%d\n",p->no,p->name,p->age);
        p=p->next;
    }
    p=head;
}
node* deleteNode(node *head)
{
    node *p,*q;
    p=head;
    int sayac,se,i;
    while(p!=NULL)
    {
        sayac++;
        p=p->next;
    }
    p=head;
    if(sayac%2==0) se=(sayac/2)-1;
    else se=sayac/2;
    for(i=0;i<=se;i++)
    {        
        if(i==se)
        {
            q->next=p->next;
            free(p);
        }
        q=p;
        p=p->next;
    }
    return head;
}
node* deleteSecNode(node *head,int yas)
{
    node *p,*q;
    p=head;
    int sayac;
    while(p!=NULL)
    {
        if(p->age==yas)sayac++;
        if(sayac==2)
        {
            q->next=p->next;
            free(p);
        }
        q=p;
        p=p->next;
    }
    return head ;   
}
