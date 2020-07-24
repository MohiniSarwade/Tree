  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  int data;
  Node *left,*right,*next;
  
  Node(int data)
  {
      this->data=data;
      left=right=next=NULL;
  }
};

void LinkingNextNodesOfSameLevel(Node *node)
{
    if(!node)
        return; 
    Node *tmp=node,*rightMostNode=NULL,*nextHead=NULL;
    while(tmp!=NULL)
    {
        if(tmp->left!=NULL)
        {
            if(rightMostNode==NULL)
            {
                rightMostNode=tmp->left;
                nextHead=tmp->left;
            }
        }
        if(tmp->right!=NULL)
        {
            if(rightMostNode==NULL)
            {
                rightMostNode=tmp->right;
                nextHead=tmp->right;
            }
            else
            {
                rightMostNode->next=tmp->right;
                rightMostNode=rightMostNode->next;
            }
        }
        tmp=tmp->next;
    }
    
    LinkingNextNodesOfSameLevel(nextHead);
}

void Inorder(Node *node)
{
    if(node)
    {
        Inorder(node->left);
        cout<<node->data<<" ";
        if(node->next)
            cout<<"->"<<node->next->data<<" ";
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
   
    cout<<endl<<"Linking next nodes in Samelevel"<<endl;
    LinkingNextNodesOfSameLevel(root);
    Inorder(root);
    
   return 0;
}
