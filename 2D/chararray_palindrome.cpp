#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

int main(){
	int i,j,n,m,k;
	cin >> n  ;
	char arr[n+1];
	cin >> arr;
	
	bool check= true;
	
	for(i=0;i<n;i++)
	{
		if(arr[i]!=arr[n-1-i])
		{
			check = false;
			break;
		}
	}
	if(check==true)
		cout<<"Palindrome"<<endl;
	else
	   cout<<"NOt"<<endl
	
	return 0;
}
