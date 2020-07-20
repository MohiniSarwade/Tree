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

Node *GenHB0(int &count, int h)
{
 
    if(h==0)
        return NULL;
     Node *tmp=new Node(++count);
     tmp->left=GenHB0(count, h-1);
     tmp->right=GenHB0(count,h-1);
     return tmp;
}

Node *HB0UsingMergeSort(int l,int r)
{
    int m=l+(r-l)/2;
    if(l>r)
        return NULL;
    Node* tmp=new Node(m);
    tmp->left=HB0UsingMergeSort(l,m-1);
    tmp->right=HB0UsingMergeSort(m+1,r);
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
    int count=0, h=3;
    Node *root=GenHB0(count, h);
    
    Node *root1=HB0UsingMergeSort(1,7);
    cout<<"Inorder of balance binary tree"<<endl;
    Inorder(root);
    cout<<endl<<"Inorder of balance binary tree using merge sort"<<endl;
    Inorder(root1);
}
