#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left,*right;
    
    Node(char data)
    {
        this->data=data;
        left=right=NULL;
    }
};
Node * BuildTreeFromPostfix(string s, int l)
{
    stack<Node *>st;
    for(int i=0;i<l;i++)
    { 
        if(s[i]!='*'&& s[i]!='+' && s[i]!='/')
        {
            Node *new_node=new Node(s[i]);
            st.push(new_node);
        }
        else
        {
            Node *new_node1=new Node(s[i]);
            Node *L=st.top();
            st.pop();
            Node *r=st.top();
            st.pop();
            new_node1->left=r;
            new_node1->right=L;
            st.push(new_node1);
        }
        
    }
    return st.top();
       
}

void Inorder(Node *node)
{
    if(!node)
        return;
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

int main()
{
    string s="ABC*+D/";
    int l=s.length();
    
    Node *root=BuildTreeFromPostfix(s,l);
    cout<<"Tree build sucessfully"<<endl;
    cout<<"Inorder of the tree"<<endl;
    Inorder(root);
    
    return 0;
}
