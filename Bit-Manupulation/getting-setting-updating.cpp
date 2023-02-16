#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

//for getting bit position
int getbit(int n,int pos){
	return ((n & (1<<pos))!=0);
}

//for setting bit at position
int setbit(int n,int pos)
{
	return (n | (1<<pos));
}

//update bit
int updatebit(int n,int pos,int value)
{
	//update = clearbit+setbit
	//1-clear bit
	int mask=~(1<<pos);	//that pos becomes 0
	n=n&mask;
	//2-setbit
	n=(n | (value<<pos));		//update with particular value
	return n;
}
int main(){
	int i,j,n,m,k;int pos;
	cin >> n >>pos ;
	int get=getbit(n,pos);
	cout<<get<<endl;
	int set=setbit(n,pos);
	cout<<set<<endl;
	int value;
	cin >> value;
	int update=updatebit(n,pos,value);
	cout<<update<<endl;
	return 0;
}
