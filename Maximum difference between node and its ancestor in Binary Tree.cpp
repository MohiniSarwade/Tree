int cal(Node *root, int &res)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int val=min(cal(root->left,res),cal(root->right,res));
    res=max(res,root->data-val);
    return min(root->data,val);
}

int maxDiff(Node* root)
{
    // Your code here 
    int res=INT_MIN;
    cal(root,res);
    return res;
}
