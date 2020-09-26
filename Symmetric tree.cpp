//Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

bool isSym(struct Node *l,struct Node *r)
{
    if(l==NULL && r==NULL)
        return true;
    //cout<<l->data<<" "<<r->data<<endl;
    if(l&& r&& l->data==r->data)
        return(isSym(l->left,r->right)&& isSym(l->right,r->left));
    else
        return false;
}

// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	// Code here
	
	return isSym(root,root);
}
