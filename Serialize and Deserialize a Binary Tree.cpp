//1.Store given tree in array. 2.build back tree from array created in 1.

void serialize(Node *root,vector<int> &A)
{
    //Your code here
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    A.push_back(root->data);
    while(q.size()!=1)
    {
        Node *tmp=q.front();
        q.pop();
        if(tmp==NULL)
        {
            q.push(NULL);
          
        }
        else
        {
            if(tmp->left)
            {
                q.push(tmp->left);
                A.push_back(tmp->left->data);
            }
            else
                A.push_back(-1);
           
            if(tmp->right)
            {
                q.push(tmp->right);
                A.push_back(tmp->right->data);
            }
             else
                A.push_back(-1);
           
           
        }
    }
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   //Your code here
    
   int i=0;
    Node *new_node=new Node(A[i]);
    queue<Node *>q;
    q.push(new_node);
  
    while(!q.empty())
    {
        Node *tmp=q.front();
        q.pop();
        if(A[i+1]!=-1)
        {
            Node *x=new Node(A[i+1]);
            tmp->left=x;
            q.push(x);
        }
        
        if(A[i+2]!=-1)
        {
            
            Node *x=new Node(A[i+2]);
            tmp->right=x;
            q.push(x); 
        
        }
        i+=2;
    }
    
    return new_node;
    
}
