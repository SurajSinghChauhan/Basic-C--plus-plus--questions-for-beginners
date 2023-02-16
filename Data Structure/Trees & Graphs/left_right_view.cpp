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
//right view and level order
void rightview(Node* root){
	if(root==NULL){
		return NULL;
	}
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *node= q.front();
			q.pop();
			
			if(i==n-1){
				cout<<node->data<<" ";
			}
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
			
		}
	}
}
//leftView
void leftview(Node* root){
	if(root==NULL){
		return NULL;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){

		int n=q.size();
		for(int i=0;i<n;i++){
			Node *node=q.front();
			q.pop();
			if(i==1){
				cout<<node->data<<" ";
			}
			
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
		}
	}
}
int main()
{
	int pre[]={1,2,4,3,5};
	int in[]={4,2,1,5,3};
	Node* root = buildTree(pre,in,0,4);
	inorderprint(root);
	return 0;
}
