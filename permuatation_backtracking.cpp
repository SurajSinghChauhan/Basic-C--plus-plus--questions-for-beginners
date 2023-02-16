#include<iostream>
#include "bits/stdc++.h"
#include <vector>
#include<climits>

using namespace std;

vector<vector<int> > ans;

/* ------------------------------------(TRICK IN STL)------------------------------------------------------------------------------
sort(nums.begin(), nums.end());
do{
	ans.push_back(nums);
}while(next_permutation(nums.begin() , nums.end()));
*/

void permutate(vector<int> &a, int idx){
	
	if(idx==a.size()){
		ans.push_back(a);
		return;
	}
	for(int i=idx;i<a.size();i++)
	{
		//if numbers are same then
		if(i!=idx && a[i]==a[idx])
			continue;		
		swap(a[i],a[idx]);
		permutate(a,idx+1);
		swap(a[i],a[idx]);
	}
	return;
}

int main(){
	int i,j,n,m,k;
	cin >>n;
	vector<int > a(n);
	for(auto &v : a)
		cin >> v;
	permutate(a,0);
	for(auto v: ans){
		for(auto b:v)
			cout << b <<" ";
		cout << endl;
	}
	return 0;
}
/*
10101
11111
01010
10011
11101
*/

