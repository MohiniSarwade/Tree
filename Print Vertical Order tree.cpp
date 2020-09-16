#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right; 
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

vector<Node *> verticalOrder(Node *root)
{
   vector<Node *> res;
   int hd=0;
   map<Node *,int>mh;
   queue<Node *> q;
   q.push(root);
   mh[root]=hd;
   int Min=INT_MAX,Max=INT_MIN;
   while(!q.empty())
   {
       
       Node *temp=q.front();
       q.pop();
       hd=mh[temp];
       if(Min>hd)
            Min=hd;
       if(Max<hd)
        Max=hd;
       //m[hd].push_back(temp->data);
       if(temp->left!=NULL)
       {
           mh[temp->left]=hd-1;
           q.push(temp->left);
       }
       if(temp->right!=NULL)
       {
           mh[temp->right]=hd+1;
           q.push(temp->right);
       }
   }
   
     for(int i=Min;i<=Max;i++)
     {
         for(auto it=mh.begin();it!=mh.end();it++)
         {
              if(it->second==i)
                res.push_back(it->first);
         }
         res.push_back(NULL);
            
     }
     return res;
}

int main()
{
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    root->right->right->left= new Node(10); 
    root->right->right->left->right= new Node(11); 
    root->right->right->left->right->right= new Node(12); 
    cout << "Vertical order traversal is \n"; 
    vector<Node *>v=verticalOrder(root); 
    
    for(int i=0;i<v.size();i++)
        if(v[i]==NULL)
            cout<<endl;
        else
            cout<<v[i]->data<<" ";
    return 0;
}

