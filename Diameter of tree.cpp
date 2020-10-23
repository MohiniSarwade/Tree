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

int diameter_tree(Node *node,int &ptr)
{
  
    if(!node)
        return 0;
   int left=diameter_tree(node->left, ptr);
   int right=diameter_tree(node->right,ptr);
   
   if(left+right>ptr)
        ptr=left+right;    
    return max(left,right)+1;
   
}

int main()
{
   Node *root= new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);
   root->left->right->left=new Node(8);
   int ptr=0;
   
  int h=diameter_tree(root,ptr);
   cout<<"Diameter of the tree "<<ptr+1<<endl;
  
   
  
   return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int height(Node *node)
{
    if(node==NULL)
        return 0;
    return max(height(node->left),height(node->right))+1;
}
int diameter(Node* node) {
    // Your code here
    if(node==NULL)
        return 0;
    int lh=height(node->left);
    int rh=height(node->right);
    int ldiam=diameter(node->left);
    int rdiam=diameter(node->right);
    
    return max((lh+rh+1),max(ldiam,rdiam));
}
