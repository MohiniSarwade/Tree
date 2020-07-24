  
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

int maxPathSum(Node *node,int &maxVal)
{
    if(!node)
        return 0;
    int leftSum=maxPathSum(node->left,maxVal);
    int rightSum=maxPathSum(node->right,maxVal);
    if(leftSum<0 && rightSum<0)
     {
         maxVal=max(maxVal,node->data);
         return node->data;
     }
    if(leftSum>0 && rightSum>0)
        maxVal=max(maxVal,leftSum+rightSum+node->data);
    int maxValUp=max(leftSum,rightSum)+node->data;
    maxVal=max(maxVal,maxValUp);
    //cout<<endl<<maxVal<<endl;
    return maxValUp;
}
int maxSum(Node *root)
{
    int maxVal=INT_MIN;
    int m=maxPathSum(root,maxVal);
    return maxVal;
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
   
    cout<<"Maximum Path sum is "<<maxSum(root);
    
   return 0;
}
