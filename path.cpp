#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int path(int s,int e)
{
	if(s==e)
	{
		return 1;
	}
	if(s>e)
		return 0;
	
	int c=0;
	for(int i=0;i<e;i++)
	{
		c+=path(s+i,e);
	}
	return c;
}

int main(){
	int i,j,n,m,k;
	
	cout<<path(0,3)<<endl;
	
	
	return 0;
}
