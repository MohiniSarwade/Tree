bool Anc(struct Node *root,int target, vector<int>&ans)
{
    if(root==NULL)
        return false;
    if(root->data==target)
        return true;
    if(Anc(root->left,target,ans)||Anc(root->right,target,ans))
    {
        ans.push_back(root->data);
        return true;
    }
    return false;
}
vector<int>Ancestors(struct Node *root, int target)
{
     // Code here
     vector<int>ans;
     bool a=Anc(root,target,ans);
     return ans;
}
