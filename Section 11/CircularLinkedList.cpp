#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *Head;

void create(int A[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);
    cout << endl;
}

void RDisplay(Node *h)
{
    static bool flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int Length()
{
    int len = 0;
    Node *h = Head;
    do
    {
        len++;
        h = h->next;
    } while (h != Head);
    return len;
}

void Insert(int pos, int x)
{
    Node *h = Head;
    Node *t;
    int i;
    if (pos < 0 || pos > Length())
        return;
    if (pos == 0)
    {
        t = new Node;
        t->data = x;

        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            h = Head;
            while (h->next != Head)
            {
                h = h->next;
            }
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        h = Head;
        for (i = 0; i < pos - 1; i++)
        {
            h = h->next;
        }
        t = new Node;
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}

int Delete(Node *p, int index)
{
    Node *q;
    int i;
    int x = -1;
    if (index < 0 || index > Length())
        return -1;
    if (index == 1)
    {
        p = Head;
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (p == Head)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        p = Head;
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int n;
    cout << "Enter the  size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    create(A, n);
    Insert(3, 100);
    RDisplay(Head);
    cout << endl;
    cout << Delete(Head, 3) << endl;
    RDisplay(Head);

    return 0;
}