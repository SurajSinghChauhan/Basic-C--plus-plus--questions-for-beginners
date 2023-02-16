#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int pathmaze(int n,int i,int j)
{
	if(i==n-1 && j==n-1)
	{
		return 1;
	}
	if(i>=n||j>=n)
		return 0;
	
	return pathmaze(n,i+1,j)+pathmaze(n,i,j+1);
}
int main(){
	int i,j,n,m,k;
	
	cin>>n;
	pathmaze(n,0,0);
	
	return 0;
}
