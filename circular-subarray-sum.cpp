#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
#define MAX 1000000
using namespace std;

int kadane(int a[],int n)
{
	int currentSum=0;
	int maxSum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		currentSum+=a[i];
		if(currentSum<0)
		{
			currentSum=0;
		}
		maxSum=max(currentSum,maxSum);
	}
	return maxSum;	
}

int main(){
	int i,j,k;int n;
	cin >> n ;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int nonWrapSum;
	nonWrapSum=kadane(a,n);
	cout << "\n\nOptimised soln is: --- ";
	
	int totalSum=0;
	for(i=0;i<n;i++)
	{
		totalSum+=a[i];
		a[i]=-a[i];

	}
	int wrapSum= totalSum +kadane (a,n);
	cout<< max(wrapSum,nonWrapSum);
	return 0;
}
	
