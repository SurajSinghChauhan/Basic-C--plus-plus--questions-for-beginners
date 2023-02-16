#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int subset(int arr[],int n)
{
	vector<int> v; 
	map<vector<int>,int>mp;int occurence=1;
	int sum=0;int mx=0;
	for(int i=0;i<(1<<n);i++)					// 1<<n = 2^n
	{
		occurence=1;sum=0;ci
		for(int j=0;j<n;j++)
		{
		if( i & (1<<j)){

			v.push_back(arr[j]);
			sum+=arr[j];
	}
	}
	mp[v]++;
	cout<<mp[v]<<endl;
	v.clear();
	}
	
	for(auto it1 = mp.begin(); it1 != mp.end(); ++it1){
		cout << (*it1).second << ": ";
		for(auto it2 = it1->first.begin(); it2 != it1->first.end(); ++it2)
    		cout << *it2 << " ";
    
    	cout<<endl;
	}
}
int main(){
	int i,j,n,m,k;

	int arr[6]={10 ,8 ,-20, 5 ,5 ,5};
	subset(arr,6);
	return 0;
}
