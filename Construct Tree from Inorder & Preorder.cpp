Node * BT(int pre[], int s, int e, unordered_map<int,int>&mp,int &index)
{
   
    if(s>e)
        return NULL;
     int x=mp[pre[index]];
    struct Node *n=new Node(pre[index]);
    index++;
    if(s==e)
        return n;
   
    n->left=BT(pre,s,x-1,mp,index);
    n->right=BT(pre,x+1,e,mp,index);
    return n;
}

Node* buildTree(int in[],int pre[], int n)
{
//add code here.
    unordered_map<int, int>mp;
    for(int i=0;i<n;i++)
        mp[in[i]]=i;
    int index=0;
    
    return BT(pre,0,n-1,mp,index);
}
