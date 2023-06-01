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

int count(Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    createTree();
    cout << "Count: " << count(root) << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    cout << "Postorder: ";
    Postorder(root);
    cout << endl;
    return 0;
}