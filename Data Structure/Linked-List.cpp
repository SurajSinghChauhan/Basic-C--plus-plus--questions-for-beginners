#include<iostream>
#include "bits/stdc++.h"
#include <vector>
#include<climits>

using namespace std;

class node{
	public:
		int data;
		node* next;
	
	node(int val){
		data=val;
		next=NULL;
	}
};

void insertAtBeg(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;		
}

void insertAtLast(node* &head,int val)
{
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}

bool search(node* head,int val)
{
	node* temp=head;
	int f=0,j=0;
	while(temp!=NULL)
	{
		if(temp->data==val){
			f=1;j++;
			break;
		}j++;
		temp=temp->next;
	}
	if(f==1)
		cout<<"Found at "<<j<<" "<<temp->data<<endl;
	else
		cout<<"NOT FOUND"<<endl;
}

void delatbeg(node* &head)
{
	node* temp=head;
	head=head->next;
	delete temp;
}

void deletion(node* &head,int val)
{
	node* temp=head;
	if(head==NULL){
		return;
	}
	if(temp->next==NULL || temp->next->next==NULL){
		delatbeg(head);
		return;
	}
	while(temp->next!=NULL)
	{
		if(temp->next->data==val){		
			break;
		}
		temp=temp->next;
	}
	node* de=temp->next;
	temp->next=temp->next->next;
	delete de;
}

void reverse(node* &head)
{
	node* prev=NULL,*current=NULL,*nxt=NULL;
	current=head;
	while(current!=NULL)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
	
	}
	head=prev;
}


node* reversek(node* &head,int k)
{
	node* prev=NULL,*nxt;
	node* current=head;
	
	int count=0;
	while(current!=NULL && count<k)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		count++;
	}
	
	if(nxt!=NULL)
	{
		head->next= reversek(nxt,k);	
	}
	
	return prev;
}


void display(node* head)
{
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<endl;
}

//MAKING OF CYCLE

void makecycle(node* &head,int pos)
{
	node* temp=head;
	node* strt;
	int count=0;
	while(temp->next!=NULL)
	{
		if(count==pos){
			strt=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=strt;
}

//DETECTING CYCLE IN A LINKED-LIST

bool detectcycle(node* &head)
{
	node* slow=head,*fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}

//REMOVE CYCLE

void remcycle(node* &head)
{
	node* slow=head,*fast=head;
	
	do{
		
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next)
	{
		fast=fast->next;
		slow=slow->next;
	}
	slow->next=NULL;
}


int main(){
	
	node* head=NULL;
	insertAtLast(head,1);
	insertAtLast(head,12);
	insertAtLast(head,15);
	insertAtLast(head,18);
	insertAtBeg(head,19);
	display(head);
	search(head,18);
	deletion(head,18);
	display(head);
	reverse(head);
	display(head);
	node* newhead=reversek(head,2);
	display(newhead);
	makecycle(newhead,2);
	cout<<detectcycle(newhead)<<endl;
	remcycle(newhead);

	
	return 0;
}


