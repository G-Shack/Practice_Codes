#include <iostream>
using namespace std;
struct Queue
{
    int Size;
    int Front;
    int Rear;
    int *Q;
};

void create(Queue *q, int n)
{
    q->Size = n;
    q->Q = new int[n];
    q->Front = q->Rear = -1;
}

void enqueue(Queue *q, int x)
{
    if (q->Rear == q->Size - 1)
        cout << "Queue if full" << endl;
    else
    {
        q->Rear++;
        q->Q[q->Rear] = x;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if (q->Front == q->Rear)
        cout << "Queue is empty" << endl;
    else
    {
        q->Front++;
        x = q->Q[q->Front];
    }
    return x;
}

void Display(Queue q)
{
    int i = 0;
    for (i = q.Front + 1; i <= q.Rear; i++)
        cout << q.Q[i] << " ";
    cout << endl;
}

int main()
{
    Queue q;
    int n = 0;
    cout << "Enter the queue size: ";
    cin >> n;
    create(&q, n);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    Display(q);

    dequeue(&q);

    Display(q);

    return 0;
}