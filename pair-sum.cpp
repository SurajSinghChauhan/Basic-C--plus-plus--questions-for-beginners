#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


bool pairsum(int a[],int n,int k)
{
	int low=0,high=n-1;
	while(low<high)
	{
		if(a[low]+a[high]==k)
		{
			cout << low+1 <<" " << high+1<<endl;
			return true;
		}
		else if((a[low]+a[high])>k)
		{
			high--;
		}
		else{
			low++;
		}
	
	}
	return false;
}
int main(){
	int i,j,k;int n;
	cin >> n >> k ;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	bool g=pairsum(a,n,k);
	cout<< g <<endl;
	return 0;
}
	
