#ifndef Queue_h
#define Queue_h

using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[size];
}

void enqueue(Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue Full!";
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node *dequeue(Queue *q)
{
    Node *x = 0;
    if (q->front == q->rear)
        cout << "Queue Empty!\n";
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(Queue q)
{
    return q.front == q.rear;
}

#endif
