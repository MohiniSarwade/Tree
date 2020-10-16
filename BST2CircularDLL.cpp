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

Node *Append(Node *a,Node *b)
{
    Node *aleft,*bleft;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    aleft=a->left;
    bleft=b->left;
    aleft->right=b;
    b->left=aleft;
    bleft->right=a;
    a->left=bleft;
    return a;
}

Node* BST2DLL(Node *node)
{
    if(node==NULL)
        return NULL;
    Node *alist=BST2DLL(node->left);
    Node *blist=BST2DLL(node->right);
    node->left=node;
    node->right=node;
    alist=Append(alist,node);
    alist=Append(alist,blist);
    return alist;
}

void print(Node *head)
{
    int count=0;
    Node *tmp=head;
    cout<<"List content:"<<endl;
   do
    {
      cout << tmp->data << " ";
      tmp = tmp->right;
      count += 1;

    }while (tmp != head);
    cout<<endl<<"List has total nodes= "<<count<<endl;
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
  
    cout<<"conversion"<<endl;
    root=BST2DLL(root);
    print(root);
   return 0;
}

