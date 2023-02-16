#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

int setBit(int n,int pos)
{
	return ((n & (1<<pos))!=0);
}
int unique(int arr[],int n)
{
	
	int xorsum=0;
	for(int i=0;i<n;i++)		//unique
	{
		xorsum=xorsum^arr[i];
	}
	int tempx=xorsum;
	int setbit=0;int pos=0;
	while(setbit!=1){
		setbit=xorsum &1;
		pos++;
		xorsum= xorsum >>1;
	}
	int newxor=0;
	for(int i=0;i<n;i++)
	{
		if(setBit(arr[i],pos-1))
		{
			newxor=newxor^arr[i];
		}
	}
	cout<<newxor<<endl;
	cout << (tempx^newxor) << endl;
}
int main(){
	int i,j,n,m,k;

	int arr[6]={1,2,3,4,1,2};
	unique(arr,6);
	return 0;
}
