#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

bool powerof2(int n)
{
	return (n&& !( n &n-1));
}
int main(){
	int i,j,n,m,k;
	cin >> n  ;
	cout << powerof2(n)<<endl;
	return 0;
}
