#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int inclusion_exclusion(int n,int a,int b)
{
	int c1=n/a;
	int c2=n/b;
	int c3=n/(a*b);
	
	return c1+c2-c3;
}

int main(){
	int i,j,n,m,k;

	cin >> n;
	int f=inclusion_exclusion(n,a,b);
	cout << "Principle is: "<<f<<endl;
	
	return 0;
}
