#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  int data;
  Node *left,*right;
  
  Node(int data)
  {
      this->data=data;
      left=right=NULL;
  }
};

Node * inorder_floor(Node *node,Node *prv,int key)
{
    stack<Node *>s;
    
    while(1)
    {
        while(node)
        {
            s.push(node);
            node=node->left;
        }
    
    if(s.empty())
        break;
    
    node=s.top();
    s.pop();
    if(node->data==key)
        return node;
    if(node->data>key)
        return prv;
    
    prv=node;
    //cout<<prv->data<<" ";
    node=node->right;
    
    }
    return prv;
}

Node *inorder_ceil(Node *node, Node *prv, int key)
{
    stack<Node *>s;
    while(1)
    {
        while(node)
        {
            s.push(node);
            node=node->right;
        }
        
        if(s.empty())
            break;
        node=s.top();
        s.pop();
        if(node->data==key)
            return node;
        if(node->data<key)
            return prv;
        prv=node;
        node=node->left;
    }
    
    return prv;
}

int main()
{
   Node *root= new Node(4);
   root->left=new Node(2);
   root->right=new Node(8);
   root->right->left=new Node(5);
   root->right->right=new Node(9);
   root->right->left->right=new Node(7);
   root->right->left->right->left=new Node(6);
  
  Node *prv=NULL;
  int key=10;
  Node *res=inorder_floor(root,prv,key);
  if(res==NULL)
    cout<<"Floor of "<<key<<" in the tree is: NULL"<<endl;
  else
     cout<<"Floor of "<<key<<" in the tree is: "<<res->data<<endl;
    
  Node *resl=inorder_ceil(root,prv,key);
  if(resl==NULL)
    cout<<"Ceil of "<<key<<" in the tree is: NULL";
  else
     cout<<"Ceil of "<<key<<" in the tree is: "<<resl->data;
   
   return 0;
}


