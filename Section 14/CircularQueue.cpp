#include <iostream>
using namespace std;

struct CQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(CQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

void Cenqueue(CQueue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is Full\n";
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int Cdequeue(CQueue *q)
{
    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is empty\n";
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(CQueue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    CQueue q;
    create(&q, n);
    Cenqueue(&q, 10);
    Cenqueue(&q, 20);
    Cenqueue(&q, 30);
    Cenqueue(&q, 40);
    Cdequeue(&q);
    Cdequeue(&q);
    Cenqueue(&q, 50);
    Cenqueue(&q, 60);
    Display(q);

    return 0;
}