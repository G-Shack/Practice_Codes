#include <iostream>
#include "QueueCPP.h"

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void Preorder() { Preorder(root); };
    void Preorder(Node *p);
    void Postorder() { Postorder(root); };
    void Postorder(Node *p);
    void Inorder() { Inorder(root); };
    void Inorder(Node *p);
    int Height() { return Height(root); };
    int Height(Node *root);
    void LevelOrder() { LevelOrder(root); }
    void LevelOrder(Node *root);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child for " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child for " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::LevelOrder(Node *root)
{
    struct Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.Preorder();
    cout << endl;
    t.Postorder();
    cout << endl;
    t.Inorder();
    cout << endl;
    t.LevelOrder();
    cout << endl;
    cout << t.Height() << endl;

    return 0;
}