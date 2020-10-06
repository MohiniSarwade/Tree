void Map(Node *root,int x,map<int,int>&mp)
{
    if(root==NULL)
        return;
    mp[x]+=root->data;
    Map(root->left,x-1,mp);
    Map(root->right,x+1,mp);
}
vector <int> verticalSum(Node *root) {
    // add code here.
    map<int,int>mp;
    Map(root,0,mp);
    vector<int>v;
    
        for(auto j:mp)
        {
           v.push_back(j.second);
        }
    return v;
}
