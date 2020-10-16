#include<iostream>
#include<queue>
using namespace std;
struct bnode
{
	int data;
	bnode *left;
	bnode *right;
};
bnode* createnewnode(int data)
{
	bnode *node=new bnode();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}
bnode* insert(bnode *root,int data)
{
	if(root==NULL)
	{
		root=createnewnode(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}


void levelorder(bnode *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		queue<bnode *> q;
		q.push(root);
		while(!q.empty())
		{
			bnode *current=q.front();
			cout<<current->data<<" ";
			if(current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
		}
	}
	cout<<"\n";
}


int main()
{
	int item,n,num;
	bnode *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,16);
	root=insert(root,27);
	levelorder(root);
	return 0;


}
