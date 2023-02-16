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

Node* sortedArraytoBST(int arr[],int start, int end){
	if(start>end){
		return NULL;
	}
	
	int mid=(start+end)/2;
	Node* root=new Node(arr[mid]);
	
	root->left=sortedArraytoBST(arr,start,mid-1);
	root->right=sortedArraytoBST(arr,mid+1,end);
	
	return root;
	
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
	int arr[]={10,2,1,13,11};
	int n=5;
	Node* root=sortedArraytoBST(arr,0,n-1);
	printpreorder(root);
}

