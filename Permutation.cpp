#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;


int permutation(string s,string ans)
{
	if(s.length()==0)
	{
		cout << ans<<endl;
	}
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];    //fixing character
		string ros = s.substr(0,i)+s.substr(i+1); // fix se phle ki add ho ri fix ke bad se
		
		permutation(ros,ans+ch);
	}
}

int main(){
	int i,j,n,m,k;
	string s;
	cin >> s;
	
	permutation(s,"");
	
	return 0;
}
