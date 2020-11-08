Node*BuildTree(int pre[],int &index,int key,int low, int high, int n)
{
    if(index>=n)
        return NULL;
    Node *node=NULL;
    if(key>low && key<high)
    {
        node=new Node();
        node->data=key;
        index=index+1;
        if(index<n)
            node->left=BuildTree(pre,index,pre[index],low,key,n);
        if(index<n)
            node->right=BuildTree(pre,index,pre[index],key,high,n);
    }
    return node;
}
Node* constructTree(int pre[], int size) {
    //code here
    int index=0;
    Node *node=BuildTree(pre,index,pre[0],INT_MIN,INT_MAX,size);
    return node;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node* constructTree(int pre[], int size) {
    //code here
    stack<Node*>s;
    Node *new_node=new Node();
    new_node->data=pre[0];
    s.push(new_node);
    
    for(int i=1;i<size;i++)
    {
        Node* tmp=NULL;
        while(!s.empty() && pre[i]>s.top()->data)
        {
            tmp=s.top();
            s.pop();
        }
        if(tmp!=NULL)
        {
            Node *node=new Node();
            node->data=pre[i];
            tmp->right=node;
            s.push(tmp->right);
        }
        else
        {
            Node *x=s.top();
             Node *node=new Node();
            node->data=pre[i];
            x->left=node;
            s.push(x->left);
        }
        
    }
    return new_node; 
}
