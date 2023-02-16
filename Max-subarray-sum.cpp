#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
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
	int mx=INT_MIN;
	cout << "Printing possible subarrays"<<endl;
	
	
	
//i
	//sabse bekar approach
	map<vector<int>,int> mp;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			int sum=0;
			for(k=i;k<=j;k++)
			{	
				sum+=a[k];
				cout<<a[k]<<" ";
			}
			mx=max(sum,mx);
			cout<<endl;
		}
	}
	cout<<"MAx of subarray is : "<<mx<<endl;
	//yaha tak
	
	
	
	
	
//ii
	//(cumulative sum appraoch)
	cout<<"new approach"<<endl;
	mx=INT_MIN;
	int currsum[n+1];
	currsum[0]=0;
	for(i=1;i<=n;i++)
	{
		currsum[i]=currsum[i-1]+a[i-1];
		
	}
	cout<<"---------"<<endl;
	for(i=1;i<=n;i++)
		cout<<currsum[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		int sum=0;
		for(j=0;j<i;j++)
		{
			sum=currsum[i]-currsum[j];
			mx=max(mx,sum);
		}
	}
	cout<<mx<<endl;
	//yaha tak
	
	


//iii
	//kadane's algorithm(optimised approach)
	int currentSum=0;
	int maxSum=INT_MIN;
	int occurence=1;
	for(i=0;i<n;i++)
	{
		currentSum+=a[i];
		if(currentSum<0)
		{
			currentSum=0;
		}

		maxSum=max(currentSum,maxSum)*occurence;
	}
	cout << "\n\nOptimised soln is: --- ";
	cout <<maxSum;
	//yaha tak
	return 0;
}
	
