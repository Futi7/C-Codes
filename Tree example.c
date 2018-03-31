#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree node;


node* insert(node *root,int data)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(root->data>data)
		return insert(root->left,data);
	return insert(root->right,data);
}


void traverse(node *root)
{
	if(root==NULL)
		return;
	traverse(root->right);
	printf("%d-",root->data);
	traverse(root->left);
}




int main()
{
	node *root=NULL;
	insert(root,10);
	insert(root,7);
	insert(root,30);
	insert(root,40);
	
	traverse(root);
	
}
