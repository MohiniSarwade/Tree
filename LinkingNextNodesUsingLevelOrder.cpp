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

void * LinkingNextNodesUsingLevelOrder(Node *node)
{
    queue<Node*>q;
    Node*prv=NULL,*tmp;
    int currentLevelCount=1,nextLevelCount=0;
    if(!node)
        return NULL;
    q.push(node);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->left)
        {
            q.push(tmp->left);
            nextLevelCount++;
        }
        if(tmp->right)
        {
            q.push(tmp->right);
            nextLevelCount++;
        }
        if(prv)
            prv->next=tmp;
        prv=tmp;
        currentLevelCount--;
        if(currentLevelCount==0)
        {
            currentLevelCount=nextLevelCount;
            nextLevelCount=0;
            prv=NULL;
        }
    }
    
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
    LinkingNextNodesUsingLevelOrder(root);
    Inorder(root);
    
   return 0;
}
