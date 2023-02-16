#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

int main(){
	int i,j,k;int n,m;int target;int flag=0;
	cin >> n >> m ;
	cin >> target;
	int a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin >> a[i][j];
	}
	int r=0,c=m-1;
	while(r<n && c>=0)
	{
		if(a[r][c]==target)
		{
			flag=1;
			break;
		}
		if(a[r][c]>target)
			c--;
		else
		   r++;
	}
	if(flag==1)
		cout<<"Element found at location: "<<r+1<<"  , "<<c+1<<endl;
	else
		cout<<"Not found";
	
	return 0;
}
	
