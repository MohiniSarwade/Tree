/*
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
*/
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

print list using bottom pointer;
*/

Node *merge(Node *a, Node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node *res;
    if(a->data<b->data)
    {
        res=a;
        res->bottom=merge(a->bottom,b);
    }
    else
    {
        res=b;
        res->bottom=merge(a,b->bottom);
    }
    res->next=NULL;
    return res;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL||root->next==NULL)
        return root;
   return merge(root,flatten(root->next));
}

