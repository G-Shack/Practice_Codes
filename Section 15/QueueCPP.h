#include <iostream>
using namespace std;

#ifndef QueueCPP
#define Queuecpp

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty();
};

void Queue::enqueue(Node *x)
{
    if ((rear + 1) % size == front)
        cout << "Queue is full\n";
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = 0;
    if (front == rear)
        cout << "Queue is empty!";
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}

#endif