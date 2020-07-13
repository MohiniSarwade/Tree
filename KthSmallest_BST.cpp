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

Node * inorder(Node *node,int k)
{
    int count=0;
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
    cout<<node->data<<" ";
    s.pop();
    if(++count==k)
        return node;
    node=node->right;
    
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
  
  int k=6;
  cout<<"Inorder"<<endl;
  Node *res=inorder(root,k);
  cout<<endl<<k<<"'th smallest of the tree is: "<<res->data;
   
   return 0;
}
