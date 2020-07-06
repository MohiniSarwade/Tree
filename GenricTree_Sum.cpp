#include<iostream>
using namespace std;

//Finding Sum of all nodes in generic tree.
struct Node
{
    int data;
    Node *Firstchild;
    Node *nextSibling;
    
    Node(int data)
    {
        this->data=data;
        Firstchild=nextSibling=NULL;
    }
};

int Sum(Node *node)
{
   
    if(!node)
        return 0;
    
    return node->data+Sum(node->Firstchild)+Sum(node->nextSibling);
    
}

int main()
{
    Node *root=new Node(1);
    root->Firstchild=new Node(2);
    root->Firstchild->Firstchild=new Node(4);
    root->Firstchild->nextSibling=new Node(3);
    root->Firstchild->Firstchild->nextSibling=new Node(5);
    root->Firstchild->Firstchild->nextSibling->nextSibling=new Node(6);
    root->Firstchild->nextSibling->Firstchild=new Node(7);
    root->Firstchild->nextSibling->Firstchild->Firstchild=new Node(8);
    root->Firstchild->nextSibling->Firstchild->Firstchild->nextSibling=new Node(9);
    
    cout<<"Sum Genric tree "<<Sum(root)<<endl;
    
    return 0;
}
