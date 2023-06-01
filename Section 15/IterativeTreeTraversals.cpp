#include <iostream>
#include "Queue.h"
#include "Stack.h"

Node *root = NULL;

void createTree()
{
    Node *p, t;
    int x;
    Queue q;
    create(&q, 100);
    cout << "Enter root: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void IPreorder(Node *p)
{
    Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            cout << p->data << " ";
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(Node *p)
{
    Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void LevelOrder(Node *p)
{
    Queue q;
    create(&q, 100);
    cout << p->data << " ";
    enqueue(&q, p);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            enqueue(&q, p->rchild);
        }
    }
}

int main()
{
    createTree();
    IPreorder(root);
    cout << endl;
    IInorder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    return 0;
}