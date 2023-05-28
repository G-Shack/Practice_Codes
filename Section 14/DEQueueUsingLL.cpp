#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

void enqueueFromRear(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Heap Full\n";
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

void enqueueFromFront(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Heap Full\n";
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            t->next = front;
            front = t;
        }
    }
}

int dequeueFromFront()
{
    int x = -1;
    Node *t = front;
    if (front == NULL)
        cout << "Queue is empty\n";
    else
    {
        x = t->data;
        front = front->next;
        delete t;
    }
    return x;
}

int dequeueFromRear()
{
    int x = -1;
    Node *p = front;
    Node *q = NULL;
    if (rear == NULL)
        cout << "Queue is empty\n";
    else
    {
        while (p->next)
        {
            q = p;
            p = p->next;
        }
        rear = q;
        q->next = NULL;
        x = p->data;
        delete p;
    }
    return x;
}

void Display()
{
    Node *t = front;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    enqueueFromRear(10);
    enqueueFromFront(20);
    enqueueFromFront(00);
    enqueueFromRear(30);
    Display();
    dequeueFromFront();
    dequeueFromRear();
    Display();
    return 0;
}