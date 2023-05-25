#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first=NULL;

void create(int A[],int n)
{
    Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t =new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }   
}

void RDisplay(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        RDisplay(p->next);
    } 
}

int main()
{
    int size;
    cout<<"Enter number of elements: \0";
    cin>>size;

    int A[size];
    cout<<"Enter Elements in the Linked List: \0";
    for(int i=0; i<size; i++)
    {
        cin>>A[i];
    }
    
    create(A, size);
    RDisplay(first);

    return 0;
}