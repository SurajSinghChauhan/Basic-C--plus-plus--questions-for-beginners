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
int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}

void inorderprint(Node* root){
	if(root==NULL){
		return;
	}
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

Node* buildTree(int preorder[], int inorder[],int start,int end)
{
	static int idx=0;
	
	if(start>end){
		return NULL;
	}
	
	int curr=preorder[idx];
	idx++;
	Node* node= new Node(curr);
	
	if(start==end)
	{
		return node;
	}
	int pos=search(inorder,start,end,curr);
	node->left=buildTree(preorder,inorder,start,pos-1);
	node->right=buildTree(preorder,inorder,pos+1,end);
	
	return node;
}

//FLATTEN A BINARY TREE
void flatten(Node* root){
	if(root==NULL || (root->left == NULL && root->right == NULL)){
		return;
	}
	if(root->left!=NULL)
	{
		flatten(root->left);
		Node* temp=root->right;
		root->right=root->left;
		root->left=NULL;
		
		Node* t=root->right;
		while(t->right!=NULL){
			t=t->right;
		}
		
		t->right=temp;
	}
	
	flatten(root->right);
}
//inorder print


int main()
{
	int pre[]={1,2,4,3,5};
	int in[]={4,2,1,5,3};
	Node* root = buildTree(pre,in,0,4);
	inorderprint(root);
	return 0;
}
