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

//O(n2)
int catalan(int n)
{
	if(n<=1){
		return 1;
	}
	
	int res=0;
	for(int i=0;i<=n-1;i++)
	{
		res+=catalan(i) * catalan(n-i-1);
	}
	
	return res;
}




//Application
vector<Node*> constructTrees(int start,int end)
{
	vector<Node*>trees;
	if(start>end){
		trees.push_back(NULL);
		return trees;
	}
	
	for(int i=start;i<=end;i++){
		vector<Node*> leftsub=constructTrees(start,i-1);
		vector<Node*> rightsub=constructTrees(i+1,end);
		
		for(int j=0;j<leftsub.size();j++){
			Node* left= leftsub[j];
			for(int k=0;k<rightsub.size();k++){
				Node* right= rightsub[k];
				Node* node = new Node(i);
				node->left=left;
				node->right=right;
				trees.push_back(node);
			}
		}
	}
	return trees;
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
	vector<Node*> totaltrees=constructTrees(1,3);
	for(int i=0;i<totaltrees.size();i++)
	{
		cout<<(i+1)<<" : ";
		printpreorder(totaltrees[i]);
		cout<<endl;
	}
	return 0;
}

