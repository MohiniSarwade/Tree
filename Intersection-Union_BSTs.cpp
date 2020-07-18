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

vector<int> inorder(Node *node)
{
    vector<int>v;
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
    //cout<<node->data<<" ";
    v.push_back(node->data);
    s.pop();
    node=node->right;
    
    }
    return v;
}

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

void Intersection(vector<int>v1,vector<int>v2)
{
    int i=0, j=0;
    while(i<v1.size()&&j<v2.size())
    {
        if(v1[i]==v2[j])
        {
            cout<<v1[i]<<" ";
            i++;
            j++;
        }
        else if(v1[i]<v2[j])
        {
            i++;
        }
        else
            j++;
    }
}

void Union(vector<int>v1,vector<int>v2)
{
    int i=0,j=0;
    while(i<v1.size()&& j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            cout<<v1[i]<<" ";
            i++;
        }
        else if(v1[i]>v2[j])
        {
            cout<<v2[j]<<" ";
            j++;
        }
        else
        {
            cout<<v1[i]<<" ";
            i++;
            j++;
        }
    }
    if(j<v2.size())
    {
        cout<<v2[j]<<" ";
        j++;
    }
    if(i<v1.size())
    {
        cout<<v1[i]<<" ";
        i++;
    }
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
    
    Node *root2 = NULL; 
    root2 = insert(root2, 10); 
    root2 = insert(root2, 7); 
    root2 = insert(root2, 20); 
    root2 = insert(root2, 4); 
    root2 = insert(root2, 9); 
    
    vector<int>v1;
    vector<int> v2;
    cout<<"Inorders"<<endl;
    cout<<"Tree 1"<<endl;
    v1=inorder(root1);
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl<<"Tree 2"<<endl;
    v2=inorder(root2);
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl<<"Intersection of tree1 & tree2"<<endl;
    Intersection(v1,v2);
    
    cout<<endl<<"Union of tree1 & tree2"<<endl;
    Union(v1,v2);
}
