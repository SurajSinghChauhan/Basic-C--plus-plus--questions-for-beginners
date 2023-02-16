#include<iostream>
#include "bits/stdc++.h"
#include <vector>
#include<climits>
#define n 100

using namespace std;

class stack{
	
	int* arr;
	int top;
	
	public:
	stack(){
		arr = new int[n];
		top=-1;
	}
	
	void push(int x)
	{
		if(top==n-1){
			cout<<"stack overflow"<<endl;
			return;
		}
		top++;
		arr[top]=x;
	}
	
	void pop(){
		if(top==-1){
			cout<<"Stack Underflow"<<endl;
			return;
		}
		cout<<"Element popped --"<<arr[top]<<endl;
		top--;
	}
	int Top(){
		if(top==-1){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}
		return arr[top];		
	}
	
	bool empty(){
		return top==-1;
	}
}st;

//REVERSING A STACK

void insertAtBottom(stack<int> &st,int ele)
{
	if(st.empty()){
		st.push(ele);
		return;
	}
	
	int tele=st.pop();
	st.pop();
	insertAtBottom(st,ele);
	
	st.push(tele);
}

void reverse(stack<int> &st)
{
	if(st.empty()){
		return;
	}
	int ele=st.Top();
	st.pop();
	reverse(st);
	insertAtBottom(st,ele);
}
int main()
{
	
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<st.Top()<<endl;
	st.pop();
	cout<<st.Top()<<endl;
	st.pop();
	st.pop();
	st.pop();
	
}

