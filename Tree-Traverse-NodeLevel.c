#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree node;

int level=1;
node* insert(node *root,int data)
{
	if(root==NULL)
	{
		node *temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	if(root->data>data)
	{
		root->left=insert(root->left,data);
		return root;
	}
	root->right=insert(root->right,data);
	return root;
}


void traverse(node *root)
{
	if(root==NULL)
		return;
	traverse(root->right);
	printf("%d\n",root->data);
	traverse(root->left);
}

void search(node *root,int data)
{
	
	if(root->data==data && root!=NULL)
	{
		printf("Aradiginiz sayi %d. seviyede bulundu.%d",level,root->data);
	}
	if(data>root->data && root->right!=NULL)
	{
		level++;
		search(root->right,data);
		}	
	if(data<root->data&& root->left!=NULL)
	{
		level++;
		search(root->left,data);
	}
	return;	
}




int main()
{
	node *root=NULL;
	root=insert(root,10);
	root=insert(root,7);
	root=insert(root,13);
	root=insert(root,40);
	root=insert(root,46);
	root=insert(root,64);
	root=insert(root,12);
	root=insert(root,39);
	root=insert(root,41);
	root=insert(root,24);
	traverse(root);
	printf("Aramak istediðiniz sayýyý girin.");
	int aranan;
	scanf("%d",&aranan);
	while(aranan!=0)
	{
	search(root,aranan);
	scanf("%d",&aranan);
	level=1;
}
return 0;
}
