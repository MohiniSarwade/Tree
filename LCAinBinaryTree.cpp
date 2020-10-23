bool findpath(Node *node,vector<Node*> *path,int k)
{
    if(node==NULL)
        return false;
    path->push_back(node);
    if(node->data==k)
        return true;
    if((node->left && findpath(node->left,path,k))||(node->right) &&findpath(node->right,path,k))
        return true;
    path->pop_back();
    return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   if(root==NULL)
    return NULL;
   vector<Node *>path1;vector<Node *>path2;
   if(!findpath(root,&path1,n1)||!findpath(root,&path2,n2))
    return NULL;
    int i;
   for(i=0;i<path1.size() && i<path2.size();i++)
   {
       if(path1[i]!=path2[i])
            break;
   }
   return path1[i-1];
}
