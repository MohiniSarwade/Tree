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

Node *Insertion_BST(Node *node, int n)
{
    if(node==NULL)
    {
        Node *new_node=new Node(n);
        return new_node;
    }
    else
    {
        if(n<node->data)
            node->left=Insertion_BST(node->left,n);
        else if(n>node->data)
            node->right=Insertion_BST(node->right,n);
    }
    
    return node;
}
void levelOrder(Node *node)
{
    queue<Node*>q;
    if(node==NULL)
        return;
    
    q.push(node);
        
        while(!q.empty())
        {
            Node *tmp=q.front();
            q.pop();
            cout<<tmp->data<<" ";
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    
}
void inorder(Node* node)
{
    if(!node)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main()
{
   Node *root= new Node(6);
   root->left=new Node(2);
   root->right=new Node(8);
   root->left->left=new Node(1);
   root->left->right=new Node(4);
   root->left->left->left=new Node(3);
    
   int n=9;
   
   cout<<"Insering "<<n<<" in the tree"<<endl;
   Node *root1=Insertion_BST(root,n);
   cout<<"Inserion Sucessfull"<<endl;
   cout<<"level order traversal"<<endl;
   levelOrder(root1);
   cout<<endl<<"Inorder traversal"<<endl;
   inorder(root1);
   return 0;
}
