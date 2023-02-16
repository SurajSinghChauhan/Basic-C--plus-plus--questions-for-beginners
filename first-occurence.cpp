#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

int main(){
	int i,j,k,pd;
	int n;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	const int N=1e6 +2;
	vector<int> ar(N, -1);
	int mini=MAX;
	for(int i=0;i<n;i++)
	{
		if(ar[a[i]]==-1)
		{
			ar[a[i]]=i;
		}
		else
			mini=min(mini,ar[a[i]]);
		
	}
	if(mini==MAX)
		cout << -1;
	else 
	cout << mini+1 << endl;
}
