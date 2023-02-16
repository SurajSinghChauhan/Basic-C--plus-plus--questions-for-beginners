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
//SHORTEST DISTANCE BETWEEN TWO NODES
Node* LCA(Node* root,int n1,int n2){
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	
	Node* left=LCA(root->left,n1,n2);
	Node* right=LCA(root->right,n1,n2);
	
	if(left !=NULL && right!=NULL){
		return root;
	}
	if(left==NULL && right==NULL)
		return NULL;
	if(left!=NULL)
	 	return LCA(root->left,n1,n2);
	return LCA(root->right,n1,n2);
}
int findh(Node* root,int k,int dist){
	if(root==NULL){
		return -1;
	}
	if(root->data==k){
		return dist;
	}
	int left=findh(root->left,k,dist+1);
	if(left!=-1){
		return -1;
	}
	return findh(root->right,k,dist+1);
}
int dist(Node* root,n1,n2){
	Node *lca=LCA(root,n1,n2);
	
	int d1=findh(lca,n1,0);
	int d2=findh(lca,n2,0);
	return d1+d2;
}

int main()
{
	int pre[]={1,2,4,3,5};
	int in[]={4,2,1,5,3};
	Node* root = buildTree(pre,in,0,4);
	inorderprint(root);
	return 0;
}
