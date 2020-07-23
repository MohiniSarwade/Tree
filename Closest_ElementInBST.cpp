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

int ClosetInBST_LevelOrder(Node *node, int key)
{
    
    int mindiff=INT_MAX;
    Node *tmp,*res;
    
    if(node==NULL)
        return 0;
    queue<Node *>q;
    q.push(node);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        //cout<<tmp->data<<endl;
        if((abs(tmp->data-key))<mindiff)
        {
            mindiff=abs(tmp->data-key);
            res=tmp;
        }
        //cout<<mindiff<<" "<<endl;
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    return res->data;
    
}

int ClosetInBST_Rec(Node *node, int key)
{
    if(!node)
        return 0;
    if(node->data==key)
        return node->data;
    else if(node->data>key)
    {
        if(!node->left)
            return node->data;
        int tmp=ClosetInBST_Rec(node->left,key);
        return abs(tmp-key)>abs(node->data-key)?node->data:tmp;
    }
           
    else
    {
        if(!node->right)
            return node->data;
        int tmp=ClosetInBST_Rec(node->right,key);
        return abs(tmp-key)>abs(node->data-key)?node->data:tmp;
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
   
    int key=3;
    cout<<"Closest Element to "<<key<<" in the BST using levelorder traversal is "<<ClosetInBST_LevelOrder(root,key)<<endl;
   
    cout<<"Closest Element to "<<key<<" in the BST using recurssion is "<<ClosetInBST_Rec(root,key);
    
   return 0;
}
