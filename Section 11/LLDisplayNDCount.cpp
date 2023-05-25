#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first = NULL, *second=NULL, *third=NULL;

void create(int A[], int n)
{
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }

}

void create2nd()
{
    int n;
    cout<<"Enter the size of 2nd array: "<<endl;
    cin>>n;

    int *B;
    B = new int[n];
    cout<<"Enter the elements of 2nd array: "<<endl;
    for(int x=0; x<n; x++)
        cin>>B[x];

    Node *t, *last2;
    second = new Node;
    second->data=B[0];
    second->next=NULL;
    last2=second;

    for(int i=1; i<n; i++)
    {
        t=new Node;
        t->data=B[i];
        t->next=NULL;
        last2->next=t;
        last2=t;
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

int RCount(Node *p)
{
    if(p!=NULL)
        return RCount(p->next)+1;
    else
        return 0;
}

int Count(Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Sum(Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s= s+p->data;
        p=p->next;
    }
    return s;
}

int RSum(Node *p)
{
    if(p!=NULL)
        return RSum(p->next)+p->data;
    else
        return 0;
}

int Max(Node *p)
{
    int max= INT32_MIN;
    while (p!=NULL)
    {
        if(p->data>max)
            max = p->data;
        p=p->next;
    }
    return max;
}

int RMax(Node *p)
{
    if(p==0)
        return 0;
    else
    {
        int x = RMax(p->next);
        return x>p->data?x:p->data;
    }
}

Node * LSearch(Node *p, int key)
{
    while (p!=NULL)
    {
        if(key == p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

//Move to front Linear Search
Node * AdvLSearch(Node *p, int key)
{
    Node *q=NULL;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            q->next=p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p= p->next;
    }
    return NULL;
}

void Insert(Node *p,int pos, int x)
{
    if(pos<0 || pos>RCount(p))
        return;
    Node *t=new Node;
    t->data=x;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p = first;
        for(int i=0; i<pos-1 &&p; i++)
            p=p->next;
        if(p)
        {
            t->next=p->next;
            p->next=t;
        }
    }
}

void InsertInSorted(Node *p, int x)
{
    Node *t = new Node;
    t->data=x;
    if(first==NULL)
        first=t;
    else{
        while(p->next->data<x && p)
        {
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first = t;
        }
        else
        {
            t->next=p->next;
            p->next=t;
        }
    }
}

int Delete(Node *p, int pos)
{
    Node *q=NULL;
    int x=-1;
    if(pos <1 || pos> RCount(p))
        return x;
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        delete p;
    }
    else
    {
        for(int i=0; i<pos-1 && p; i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            x=p->data;
            q->next=p->next;
            delete p;
        }
    }
    return x;
}

bool isSorted(Node *p)
{
    int x=INT32_MIN;
    while (p!=NULL)
    {
        if(p->data<x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

void removeDuplicate(Node *p)
{
    Node *q = p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void Reverse1(Node *p)
{
    int *A, i=0;
    Node *q;
    A = new int[Count(first)];

    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }

}

void Reverse2(Node *p)
{
    Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    first=q;    
}

void RecReverse(Node *q, Node *p)
{
    if(p)
    {
        RecReverse(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void Concat(Node *p, Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}

void Merge(Node *p, Node *q)
{
    Node *last3 = new Node;
    if(p->data<q->data)
    {
        third=last3=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last3=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last3->next=p;
            last3=p;
            p=p->next;
            last3->next=NULL;
        }
        else
        {
            last3->next=q;
            last3=q;
            q=q->next;
            last3->next=NULL;
        }
    }
    if(p)
        last3->next=p;
    if(q)
        last3->next=q;
}

int isLoop(Node *f)
{
    Node *p,*q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q); //if they become equal this means there is a loop

    return p==q?1:0;
}


int main()
{
    int n;
    cout<<"Enter number of elements in 1st array: ";
    cin>>n;
    
    int A[n];
    cout<<"Enter the elements to store in 1st LL: \n";
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    
    
    create(A, n);
    
    // Node *t1,*t2;
    // t1 = first->next->next->next;
    // t2= first->next->next->next->next;
    // t2->next=t1;
    // cout<<isLoop(first)<<endl;

    // removeDuplicate(first);
    // RDisplay(first);

    // if(isSorted(first))
    //     cout<<"LL is sorted!"<<endl;
    // else
    //     cout<<"LL is not sorted!"<<endl;
    
    // int rcount=0,count=0;
    // rcount = RCount(first);
    // count = Count(first);
    // cout<<count<<" "<<rcount<<endl;
    
    // int sum=0, rsum=0;
    // rsum = RSum(first);
    // sum = Sum(first);
    // cout<<sum<<" "<<rsum<<endl;

    // int max=0, rmax=0;
    // rmax = RMax(first);
    // max = Max(first);
    // cout<<max<<" "<<rmax<<endl;

    // int serKey;
    // cout<<"Enter Key to Search: \n";
    // cin>>serKey;

    // Node *temp;
    // temp =  LSearch(first, serKey);
    // if(temp)
    //     cout<<"Key "<<temp->data<<" is found\n";
    // else 
    //     cout<<"Key not found!\n"; 
    
    // Node *advtemp;
    // advtemp =  AdvLSearch(first, serKey);
    // if(advtemp)
    //     cout<<"Key "<<advtemp->data<<" is found\n";
    // else 
    //     cout<<"Key not found!\n"; 

    return 0;
}

