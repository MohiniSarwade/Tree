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

Node *findmax(Node *node)
{
    if(!node)
        return NULL;
    while(node->right!=NULL)
        node=node->right;
    return node;
}

Node *Deletion_BST(Node *node, int n)
{
    if(node==NULL)
        return NULL;
    else if(n<node->data)
        node->left=Deletion_BST(node->left,n);
    else if(n>node->data)
        node->right=Deletion_BST(node->right,n);
    else
    {
        if(node->right && node->left)
        {
            Node *tmp=findmax(node->left);
            node->data=tmp->data;
            node->left=Deletion_BST(node->left,node->data);
        }
        else
        {
            Node *tmp=node;
            if(node->left==NULL)
                node=node->right;
            else if(node->right==NULL)
                node=node->left;
            delete(tmp);
        }
    }
    
    return node;
}
void inorder(Node* node)
{
    if(!node)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main()
{
   Node *root= new Node(4);
   root->left=new Node(2);
   root->right=new Node(8);
   root->right->left=new Node(5);
   root->right->right=new Node(1);
   root->right->left->right=new Node(7);
   root->right->left->right->left=new Node(6);
    
   int n=5;
   
   cout<<"Deleting "<<n<<" from the tree"<<endl;
   Node *root1=Deletion_BST(root,n);
   cout<<"Deleton was Sucessfull"<<endl;
  
   cout<<endl<<"Inorder traversal"<<endl;
   inorder(root1);
   return 0;
}
