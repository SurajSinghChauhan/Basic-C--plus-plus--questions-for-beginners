#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int primefactorisation(int n)
{
	int spf[100]={0};
	for(int i=2;i<=n;i++)
	{
		spf[i]=i;
	}
	for(int i=2;i<=n;i++)
	{
		if(spf[i]==i){
			for(int j=i*i;j<=n;j+=i)
			{
				if(spf[j]==j)
				{
					spf[j]=i;			//changes index to value of i i.e it would be multiple of that number
				}
			}
		}
	}
	cout<<"FACTOR"<<endl;
	while(n!=1)
	{
		cout << spf[n] <<" ";
		n=n/spf[n];
	}
}

// nloglogn

void primecalc(int n)
{
	int prime[100]={0};
	for(int i=2;i*i<=n;i++)   // how i*i?? because before i*i numbers were marked by previous numbers
	{	
		if(prime[i]==0)
		for(int j=i*i;j<=n;j+=i)
		{
			
			prime[j]=1;	
			
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==0)
		{
			cout<<i<<" ";
		}
	}cout<<endl;
	
	
}

int main(){
	int i,j,n,m,k;

	cin >> n;
	primecalc(n);
	primefactorisation(n);
	return 0;
}
