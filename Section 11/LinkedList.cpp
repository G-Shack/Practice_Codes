#include<iostream>
using namespace std;

template<class T> 
class Node{
    public:
    T data;
    Node<T> *next;
};

template<class T>
class LinkedList{
    private:
        Node<T> *first;
    public:
        LinkedList(){first = NULL;}
        ~LinkedList();
        void create(T A[], int n);
        void Display();
        void Insert(int pos, T x);
        T Delete(int pos);
        int Count();
};

template<class T>
LinkedList<T>:: ~LinkedList()
{
    Node<T> *p = first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
    cout<<"LinkedList Deleted.\n";
}

template<class T>
void LinkedList<T>::create(T A[], int n)
{
    Node<T> *t, *last;
    first= new Node<T>;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=new Node<T>;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

template<class T>
void LinkedList<T>::Display()
{
    Node<T> *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class T>
int LinkedList<T>::Count()
{
    Node<T> *p =first;
    int count =0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

template<class T>
void LinkedList<T>::Insert(int pos, T x)
{
    Node<T> *p = first;

    if(pos<0 || pos>Count())
        return;

    Node<T> *t = new Node<T>;
    t->data=x;
    if(pos == 0)
    {
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(int i=0; i<pos-1 && p; i++)
            p=p->next;
        if(p)
        {
            t->next=p->next;
            p->next=t;
        }
    }
}

template<class T>
T LinkedList<T>::Delete(int pos)
{
    Node<T> *p = first;
    Node<T> *q = NULL;
    T x=-1;
    if(pos<1 || pos>Count())
        return x;
    else if(pos ==1)
    {
        x=first->data;
        p=first;
        first = first->next;
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
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}

int main()
{
    int n=0;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    float A[n];
    cout<<"Enter the elements of array\n";
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    LinkedList<float> l;
    l.create(A,n);
    l.Display();
    l.Insert(3,10);
    l.Display();
    cout<<l.Delete(3)<<endl;
    l.Display();
}
