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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

vector <int> verticalOrder(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void arrange(TreeNode* root, int x, int h, map<int,vector<pair<int,int>>>&mp)
    {
        if(root==NULL)
            return;
        mp[x].push_back({h,root->val});
        arrange(root->left,x-1,h+1,mp);
        arrange(root->right,x+1,h+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>v;
        map<int,vector<pair<int,int>>>mp;
        int x=0;
        arrange(root,x,0,mp);
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<int>res;
            auto p=it->second;
            sort(p.begin(),p.end());
            for(int i=0;i<p.size();i++)
            {
                res.push_back(p[i].second);
            }           
            v.push_back(res);
            res.clear();
        }
        return v;
    }
};
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);
    	
    	vector <int> res = verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root: root node of the tree
void arrange(Node *root,int x,map<int,vector<int>>&mp)
{
    if(root==NULL)
        return;
    queue<pair<int,Node*>>q;
    q.push(make_pair(x,root));
    while(q.size())
    {
        pair<int,Node*>z=q.front();
        mp[z.first].push_back(z.second->data);
        if(z.second->left)
            q.push(make_pair(z.first-1,z.second->left));
        
        if(z.second->right)
              q.push(make_pair(z.first+1,z.second->right));
        q.pop();
    }

}
vector<int> verticalOrder(Node *root)
{
    //Your code here
    int x=0;
    map<int,vector<int>>mp;
   
    arrange(root,x,mp);
    vector<int>v;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
         for(int i=0;i<it->second.size();++i)
         {
            v.push_back(it->second[i]);
         }
    }
    return v;
}

