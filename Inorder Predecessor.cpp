#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data,data2;
    Node *left,*right,*parent;
    
    Node(int data)
    {
        this->data=data;
        left=right=parent=NULL;
        data2=0;
    }
};

Node * Inorder_Predecessor(Node *node, int &prv)
{
    if(!node)
        return NULL;
    Node *tmp=Inorder_Predecessor(node->left,prv);
    if(prv==INT_MIN)
        prv=node->data;
    if(node->data!=prv)
        node->data2=prv;
     prv=node->data;
    return Inorder_Predecessor(node->right,prv);
    
}

void Inorder(Node *node)
{
    if(node)
    {
        Inorder(node->left);
        cout<<node->data<<"->"<<node->data2<<" ";
        Inorder(node->right);
    }
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
   root->data2=6;
   root->left->data2=2;
   root->right->data2=2;

    int prv=INT_MIN;
    Node *tmp=Inorder_Predecessor(root,prv);
    
    cout<<"Inoder Traversal---Node data->Node's inorder Predecessor "<<endl;
    Inorder(root);
    return 0;
    
}
