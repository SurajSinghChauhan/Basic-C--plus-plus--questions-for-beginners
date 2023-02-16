#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> child;
};

/*void display(Node* root){
    string str= root->data+"->";
    for(auto children:root->child){
        str+=children->data +", ";
    }
    str+=".";
    cout<<str<<endl;
    for(auto children:root->child){
        display(children);
    }
}*/

int main()
{
    vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    stack<Node *> st;
    Node *root= NULL ;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==-1){
            st.pop();
        }
        else{
            Node *temp=new Node;
            temp->data=arr[i];
            if(st.size()>0){

                st.top()->child.push_back(temp);
                st.push(temp);
            }
            else
                root=temp;
        }
    }
    //display(root);
}
