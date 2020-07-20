#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data,height;
    Node *left,*right;
    
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

Node *GenAVL(int &count, int h)
{
 
    if(h<0)
        return NULL;
     Node *tmp=new Node(++count);
     tmp->left=GenAVL(count, h-1);
     tmp->height=h;
     tmp->right=GenAVL(count,h-2);
     return tmp;
}


void Inorder(Node * node)
{
    if(node)
    {
        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
    }
}

int main()
{
    int count=0, h=4;
    Node *root=GenAVL(count, h);

    cout<<"Inorder of balance binary tree"<<endl;
    Inorder(root);

}
