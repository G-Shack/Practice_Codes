#include <iostream>
using namespace std;

struct LLQueue
{
    int data;
    LLQueue *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    LLQueue *t = new LLQueue;
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

int dequeue()
{
    int x = -1;
    LLQueue *p = front;
    if (front == NULL)
        cout << "Queue is empty\n";
    else
    {
        x = front->data;
        front = front->next;
        delete p;
    }
    return x;
}

void Display()
{
    LLQueue *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    cout << dequeue() << endl;
    return 0;
}