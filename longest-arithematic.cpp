#include<iostream>
using namespace std;

int main(){
	int i,j,k,pd;
	int n;
	cin >> n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int cur=2;int ans=2;
	pd=arr[i]-arr[i-1];
	for(i=2;i<n;i++)
	{
		
		if(pd==arr[i]-arr[i-1]){
			cur++;
			
		}
		else{
			pd=arr[i]-arr[i-1];
			cur=2;
		}
		ans = max(ans , cur);
	}
	cout << ans;
	return 0;
}
