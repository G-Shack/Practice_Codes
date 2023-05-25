#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next; // null
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Insert(Node *p, int index, int x)
{
    Node *t;
    int i;
    if (index < 0 || index > Length(first))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;

        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(Node *p, int index)
{
    int x = -1, i;
    if (index < 1 || index > Length(first))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;

        x = p->data;
        delete p;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p)
{
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int n;
    cout << "Enter the length of linked list: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements in the linked list" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    Display(first);
    // cout << Delete(first, 7) << endl;
    //  Insert(first, 3, 25);
    Reverse(first);
    Display(first);

    return 0;
}