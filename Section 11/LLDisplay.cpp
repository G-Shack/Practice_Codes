#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    int size;
    cout<<"Enter size of array: \n";
    cin>>size;
    int A[size];
    cout<<"Enter elements to be added in Linked List: \0";
    for(int i=0; i<size; i++)
    {
        cin>>A[i];
    }

    create(A,size);
    display(first);
    return 0;
}