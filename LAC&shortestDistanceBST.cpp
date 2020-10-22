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

Node *LCA(Node *node, int a, int b)
{
    while(1)
    {
        if((a<=node->data && b>=node->data)||(a>=node->data && b<=node->data))
            return node;
        
        if(a<node->data)
            node=node->left;
        else
            node=node->right;
    }
    
}

int count(Node*rc, int b)
{
    int countR=0;
    while(1)
    {
        if(rc->data==b)
            break;
        if(b>rc->data)
        {
            countR++;
            rc=rc->right;
        }
        else if(b<rc->data)
        {
            countR++;
            rc=rc->left;
        }
        
    }
    return countR;
}
void SP(Node*node, int a, int b)
{
    Node *rc=LCA(node,a,b);
    int countL=0,countR=0;
    countR=count(rc,b);
    countL=count(rc,a);
    //cout<<countR<<countL;
    cout<<countR+countL;
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
    
    int a=8;
   int b=2;
   
   Node* r=LCA(root,a,b);
   cout<<"Least common ancistor of nodes "<<a<<" "<<b<<" is "<<r->data<<endl;
   
   
   if(a>b)
   {
       int tmp;
       tmp=b;
       b=a;
       a=tmp;
   }
   cout<<"shortest path between these nodes ";
   SP(root,a,b);
   return 0;
}
