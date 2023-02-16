#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

int main(){
	int i,j,n,m,k;
	cin >> n  ;
	cin.ignore(); 		//for buffer clear
	char arr[n+1];
	cin.getline(arr,n+1);		//buffer clear
	cin.ignore();
	
	int  currlen=0 , maxlen=0;
	while(1)
	{
		if(arr[i]==' '|| arr[i]=='\0')
		{
			maxlen=max(currlen,maxlen);
			currlen=0;
		}
		else
		{
			currlen++;
			printf("%d\n",i);
		}
		
	
		if(arr[i]== '\0')
		{
			printf("%d\n",i);
			break;
		}
			
			
		i++;
	}
	cout<< maxlen <<endl;
	
	
	
	return 0;
}
