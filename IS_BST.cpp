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

    bool isBST(Node *node,int &prv)
{
    if(!node)
        return true;
    if(!isBST(node->left,prv))
        return false;
    if(node->data <= prv)
        return false;
    prv=node->data;
    return isBST(node->right,prv);
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
  
  int prv=INT_MIN;
  bool t=isBST(root,prv);
  if(t==true)
    cout<<"Is a BST"<<endl;
  else 
    cout<<"Not a BST"<<endl;
   
   return 0;
}
