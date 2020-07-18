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


Node *insert(Node *node,int data)
{
    Node *new_node=new Node(data);
    if(!node)
    {
        return new_node;
    }
    if(data<node->data)
        node->left=insert(node->left,data);
    else 
        node->right=insert(node->right,data);
    return node;
}

int countTrees(int n)
{
    int sum=0;
    if(n<=1)
        return 1;
    else
    {
       
        int left,right;
        for(int root=1;root<=n;root++)
        {
            left=countTrees(root-1);
            right=countTrees(n-root);
            sum+=left*right;
        }
    }
    return sum;
}

int main()
{
   Node *root1 = NULL; 
    root1 = insert(root1, 5); 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 10); 
    root1 = insert(root1,  0); 
    root1 = insert(root1,  4); 
    root1 = insert(root1,  7); 
    root1 = insert(root1,  9); 
    
    int n=5;
    cout<<"No of BSTS possible with values "<<n<<": "<<countTrees(n)<<endl;
    
}
