#include <iostream>
#include "Queue.h"

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

void Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    createTree();
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
    return 0;
}