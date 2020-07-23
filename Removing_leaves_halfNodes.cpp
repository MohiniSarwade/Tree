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

Node * remHalfNodes(Node *node)
{
    
    if(!node)
        return NULL;
    node->left=remHalfNodes(node->left);
    node->right=remHalfNodes(node->right);
    if(node->left==NULL && node->right==NULL)
        return node;
    if(!node->left)
        return node->right;
    if(!node->right)
        return node->left;
    return node;
}

Node *remLeaves(Node *node)
{
    if(node)
    {
       if(node->left==NULL && node->right==NULL)
       {
           delete(node);
           return NULL;
       }
       else
       {
           node->left=remLeaves(node->left);
           node->right=remLeaves(node->right);
       }
    }
    return node;
}

void Inorder(Node *node)
{
    if(node)
    {
        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
    }
            
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
   
   cout<<"Orginal Tree"<<endl;
   Inorder(root);
    
    
    cout<<endl<<"Remove Leaves"<<endl;
    Node *rem=remLeaves(root);
    Inorder(rem);
    
    cout<<endl<<"Removed half Nodes from tree. new tree"<<endl;
    Node *res=remHalfNodes(root);
    Inorder(res);
    
   return 0;
}
