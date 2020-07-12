#include <iostream>

using namespace std;
class Node
{
public:
  int data;
  Node *prv;
  Node *next;
};
Node * insertAtBegin(Node *head, int num)
{
   
    Node *new_node=new Node();
    new_node->data=num;
    new_node->next=NULL;
    new_node->prv=NULL;
    if(head==NULL)
    {
        head=new_node;
        cout<<"Node inserted at begining"<<endl;
        return head;
    }
    new_node->next=head;
    head->prv=new_node;
    head=new_node;
    
    cout<<"Node inserted at begining"<<endl;
    return head;
}
Node* findMiddle(Node *head)
{
    Node *fast=head, *slow=head;
    
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        
        slow=slow->next;
        
    }
    return slow;
    
    
}

Node *DLL2BST(Node *head)
{
    Node *tmp,*p,*q;
    if(!head||!head->next)
        return head;
    tmp=findMiddle(head);
    q=tmp->next;
    p=tmp->prv;
    p->next=NULL;
    q->prv=NULL;
    tmp->next=NULL;
    tmp->prv=DLL2BST(head);
    tmp->next=DLL2BST(q);
    return tmp;
}
void print(Node *head)
{
    int count=0;
    Node *tmp=head;
    cout<<"List content:"<<endl;
    while(tmp!=NULL)
    {
        count+=1;
        cout<<tmp->data<<" ";
        tmp=tmp->next;
        
    }
    cout<<endl<<"List has total nodes= "<<count<<endl;
}
void printBST(Node *head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    printBST(head->prv);
    
    printBST(head->next);
}
int main()
{
    cout<<"Doubly linked list"<<endl;
    
    Node *head=NULL;
    
    head=insertAtBegin(head,9);
    head=insertAtBegin(head,8);
    head=insertAtBegin(head,7);
    head=insertAtBegin(head,6);
    head=insertAtBegin(head,5);
    head=insertAtBegin(head,4);
    head=insertAtBegin(head,2);
    
    print(head);
    
    head=DLL2BST(head);
    cout<<"BST preorder"<<endl;
    printBST(head);
    return 0;
}
