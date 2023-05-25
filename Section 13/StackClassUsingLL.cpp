#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *Top;

public:
    Stack() { Top = NULL; }
    void push(int x);
    int pop();
    void Display();
    int Peek();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is full\n";
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (Top == NULL)
        cout << "Stack is empty\n";
    else
    {
        x = Top->data;
        Node *t = Top;
        Top = Top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *p = Top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    stk.Display();
    stk.pop();
    stk.Display();
    return 0;
}