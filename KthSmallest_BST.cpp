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

Node * inorder(Node *node,int k)
{
    int count=0;
    stack<Node *>s;
    
    while(1)
    {
        while(node)
        {
            s.push(node);
            node=node->left;
        }
    
    if(s.empty())
        break;
    
    node=s.top();
    cout<<node->data<<" ";
    s.pop();
    if(++count==k)
        return node;
    node=node->right;
    
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int KSmallestUsingMorris(Node *root, int k) 
{ 
    // Count to iterate over elements till we 
    // get the kth smallest number 
    int count = 0; 
  
    int ksmall = INT_MIN; // store the Kth smallest 
    Node *curr = root; // to store the current node 
  
    while (curr != NULL) 
    { 
        // Like Morris traversal if current does 
        // not have left child rather than printing 
        // as we did in inorder, we will just 
        // increment the count as the number will 
        // be in an increasing order 
        if (curr->left == NULL) 
        { 
            count++; 
  
            // if count is equal to K then we found the 
            // kth smallest, so store it in ksmall 
            if (count==k) 
                ksmall = curr->key; 
  
            // go to current's right child 
            curr = curr->right; 
        } 
        else
        { 
            // we create links to Inorder Successor and 
            // count using these links 
            Node *pre = curr->left; 
            while (pre->right != NULL && pre->right != curr) 
                pre = pre->right; 
  
            // building links 
            if (pre->right==NULL) 
            { 
                //link made to Inorder Successor 
                pre->right = curr; 
                curr = curr->left; 
            } 
  
            // While breaking the links in so made temporary 
            // threaded tree we will check for the K smallest 
            // condition 
            else
            { 
                // Revert the changes made in if part (break link 
                // from the Inorder Successor) 
                pre->right = NULL; 
  
                count++; 
  
                // If count is equal to K then we found 
                // the kth smallest and so store it in ksmall 
                if (count==k) 
                    ksmall = curr->key; 
  
                curr = curr->right; 
            } 
        } 
    } 
    return ksmall; //return the found value 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
   Node *root= new Node(4);
   root->left=new Node(2);
   root->right=new Node(8);
   root->right->left=new Node(5);
   root->right->right=new Node(9);
   root->right->left->right=new Node(7);
   root->right->left->right->left=new Node(6);
  
  int k=6;
  cout<<"Inorder"<<endl;
  Node *res=inorder(root,k);
  cout<<endl<<k<<"'th smallest of the tree is: "<<res->data;
   
   return 0;
}
