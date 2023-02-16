#include<iostream>
using namespace std;

int main(){
	int i,j,k,pd;
	int n;
	cin >> n;
	int a[n+1];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int mx=a[0];int br=0;
	for(i=1;i<n;i++)
	{
		if(mx<a[i] && a[i+1]<a[i])
		{
			
			br++;
		}
		mx=max(mx,a[i]);
	}
	cout << br;
	return 0;
}
