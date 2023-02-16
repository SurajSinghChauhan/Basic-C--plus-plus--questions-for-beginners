#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

Node* constructBst(int preorder[],int *preorderidx,int key,int min ,int max,int n)
{
	if(*preorderidx>=n){
		return NULL;
	}
	
	Node* root=NULL;
	if(key>min && key<max)
	{
		root=new Node(key);
		*preorderidx=*preorderidx+1;
		
		if(*preorderidx< n){
			root->left=constructBst(preorder,preorderidx,preorder[*preorderidx],min,key,n);
		}
		if(*preorderidx< n){
			root->right=constructBst(preorder,preorderidx,preorder[*preorderidx],key,max,n);
		}
		
	}
	return root;
	
}
//isBST

bool check(Node *root,Node* min,Node* max){
	
	if(root==NULL){
		return true;
	}
	
	if(min != NULL && root->data>=min->data){
		return false;
	} 
	if(max != NULL && root->data>=max->data){
		return false;
	} 	
	
	bool left=check(root->left,min,root);
	bool right=check(root->right,root,min);
	return left and right;
}

void printpreorder(Node* root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	printpreorder(root->left);
	printpreorder(root->right);
}

int main()
{
	int preorder[]={10,2,1,13,11};
	int n=5;
	int preorderidx=0;
	Node* root=constructBst(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,n);
	printpreorder(root);
	cout<<endl;
	if(check(root,NULL,NULL)){
		cout<<"valid"<<endl;
	}
	else
		cout<<"NOT valid"<<endl;
}

