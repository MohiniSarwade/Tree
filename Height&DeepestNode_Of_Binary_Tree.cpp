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

int height_tree(Node *node)
{
  if(!node)
        return 0;
    else
    {
        int left=height_tree(node->left);
        int right=height_tree(node->right);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
}
int Height_levelorder(Node * node)
{
    int h=0;
    queue<Node *>q;
    q.push(node);
    q.push(NULL);
    while(!q.empty())
    {
        Node *tmp=q.front();
        q.pop();
        if(tmp==NULL)
        {
            if(!q.empty())
                q.push(NULL);
            h++;
        }
        else
        {
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        } 
    }
    return h;
}

int deepestNode(Node *node)
{
    queue<Node *>q;
    Node * tmp=NULL;
    if(node==NULL)
        return 0;
    q.push(node);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    return tmp->data;
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
   
   cout<<"height of tree "<<height_tree(root)<<endl;
   cout<<"Height of tree "<<Height_levelorder(root)<<endl;
   cout<<"Deepest node of the tree "<<deepestNode(root)<<endl;
   return 0;
}
