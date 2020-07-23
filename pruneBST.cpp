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

Node * pruneBST(Node *node, int A,int B)
{
    
    if(!node)
        return NULL;
    node->left=pruneBST(node->left,A,B);
    node->right=pruneBST(node->right,A,B);
    if(node->data>=A && node->data<=B)
        return node;
    if(node->data<A)
        return node->right;
    if(node->data>B)
        return node->left;
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

    cout<<endl<<"Prune BST"<<endl;
    Node *res=pruneBST(root,2,6);
    Inorder(res);
    
   return 0;
}
