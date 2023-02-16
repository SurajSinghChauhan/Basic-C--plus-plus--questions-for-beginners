#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

int main(){
	int i,j,k,pd;
	int n,s;
	cin >> n >> s;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int st=-1,end=-1,sum=0;
	i=0;j=0;
	while(j<n && sum+a[j]<=s)
	{
		sum+=a[j];
		j++;
	}
	if(sum==s)
	{
		cout<<i+1<<j<<endl;
		return 0;
	}
	while(j<n ){
		sum+=a[j];
		while(sum>s)
		{
			sum-=a[i];
			i++;
		}
		if(sum==s)
		{
			st=i+1;
			end=j+1;
			break;
		}
		j++;
	}
	
	cout << st << " "<< end;
	return 0;
}
	
