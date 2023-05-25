#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *Top = NULL;

void push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Heap is Full\n";
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int pop()
{
    int x = -1;
    Node *p;
    if (Top == NULL)
        cout << "Stack is empty!\n";
    else
    {
        p = Top;
        x = Top->data;
        Top = Top->next;
        delete p;
    }
    return x;
}

void Display()
{
    Node *p = Top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    Display();
    cout << pop() << endl;

    return 0;
}