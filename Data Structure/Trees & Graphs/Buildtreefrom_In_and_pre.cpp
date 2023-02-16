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
//sum at k nodes and level order traversal

int sumk(Node* root , int k)
{
	if(root == NULL){
		return -1;
	}
	queue<Node* > q;
	q.push(root);
	q.push(NULL);
	int level=0,sum;
	while(!q.empty()){
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			if(level==k)
				sum+=node->data;
			if(node->left!=NULL){
				q.push(node->left);}
			if(node->right!=NULL){
				q.push(node->right);
			}
			
		}
		else if(!q.empty()){
			q.push(	NULL);
			level++;
		}
		
	}
	return sum;
	
}

//Calculate diameter in O(n)
//-------------------------------------------//
int calculatediameter(Node* root, int*height)
{
	if(root==NULL)
	{
		*height=0;
		return 0;
	}
	
	int lh=0,rh=0;
	int ldiameter=calculatediameter(root->left,&lh);
	int rdiameter=calculatediameter(root->right,&rh);
	
	int currdiameter= lh+rh+1;
	*height=max(lh,rh)+1;
	
	return max(currdiameter,max(ldiameter,rdiameter));
}

// BALANCED BINARY TREE	o(n2)
int height(Node* root){
	if(root==NULL){
		return 0;
	}
	
	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh,rh)+1;
}	

bool isbalance(Node* root){
	if(root==NULL){
		return true;
	}
	
	if(isBalance(root->left)==false){
		return false;
	}
	if(isBalance(root->right)==false){
		return false;
	}
	int lh= height(root->left);
	int rh=height(root->right);
	if(abs(lh-rh)<=1){
		return true;
	}
	else 
		return false;
}
// BALANCED BINARY TREE	o(n)
bool isbalanced2(Node* root,int *height){
	if(root==NULL){
		return true;
	}	
	
	int lh=0,rh=0;
	if(isBalanced2(root->left,&lh)==false){
		return false;
	}
	if(isBalanced2(root->right,&rh)==false){
		return false;
	}
	*height=max(rh,lh)+1;
	if(abs(lh-rh)<=1){
		return true;
	}
	else 
		return false;	
}


int main()
{
	int pre[]={1,2,4,3,5};
	int in[]={4,2,1,5,3};
	Node* root = buildTree(pre,in,0,4);
	inorderprint(root);
	return 0;
}
