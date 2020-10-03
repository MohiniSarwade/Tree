void path(Node *node,vector<int>t,vector<vector<int>>&v)
{
    t.push_back(node->data);
    if(node->right==NULL && node->left==NULL)
    {
        v.push_back(t);
        return;
    }
    if(node->left)
        path(node->left,t,v);
    if(node->right)
    path(node->right,t,v);
}

vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>>v;
    vector<int>t;
    path(root,t,v);
    return v;
}
