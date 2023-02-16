#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

/*
	n =19 = 01011					n= 18 =01010			n = 16						
									n-1= 17=01001			n-1=15
	n-1=18 01010					
	
	n= n&n-1						n= n& n-1				n=n&n-1
	 = 01011 & 01010				 = 01000 = 16			 = 00000 = 0
	 = 01010 =18
	 (compare with n there is difference of just 1 the right most 1)
*/
int numberof1(int n)
{
	int count=0;
	while(n)
	{
		n=n &n-1;
		count++;
	}
	return count;
	
}
int main(){
	int i,j,n,m,k;
	cin >> n  ;
	cout << numberof1(n)<<endl;
	return 0;
}
