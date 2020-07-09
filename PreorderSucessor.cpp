#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right,*parent;
    
    Node(int data)
    {
        this->data=data;
        left=right=parent=NULL;
    }
};

Node * Preorder_Sucessor(Node *node)
{
    if(node->left)
        return node->left;
    
    Node *cur=node,*par=node->parent;
    while(par!=NULL && cur==par->right)
    {
        cur=cur->parent;
        par=par->parent;
    }
    
    if(par==NULL)
        return NULL;
    return par->right;
}

int main()
{
   Node *root= new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->left->parent=root;
   root->right->left=new Node(6);
   root->right->right=new Node(7);
   root->right->parent=root;
   root->left->right->left=new Node(8);
   root->left->right->parent=root->left;
   root->left->left->parent=root->left;
   root->right->left->parent=root->right;
   root->right->right->parent=root->right;
   root->left->right->left->parent=root->left->right;
   root->left->right->right=new Node(9);
   root->left->right->right->parent=root->left->right;

   Node *x=Preorder_Sucessor( root->left->right->right);
   if(x==NULL)
        cout<<"Preorder Sucessor of "<< root->left->right->right->data<<" is NULL "<<endl;
   else
        cout<<"Preorder Sucessor of "<< root->left->right->right->data<<" is "<<x->data<<endl;
   return 0;
    
}
