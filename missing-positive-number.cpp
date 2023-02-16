#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define MAX 1000000
using namespace std;

int main(){
	int i,j,k,pd;
	int n,s;
	cin >> n ;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	const int N = 1e6+2;
	vector<bool> check(N, false);
	for(i=0;i<n;i++)
	{
		if(a[i]>0){
			check[a[i]]=true;
		}
	}
	int ans=-1;
	for(i=1 ;i<N;i++)
	{
		if(check[i]==false) //check[i]==0 dono logic same hai
		{
			ans=i;
			break;
		}
	}
	if(ans!=false)
		cout << ans;
	else
		cout << "not found";
	
	return 0;
}
	
