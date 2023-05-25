#include <iostream>
using namespace std;

int n, m;

struct Node
{
    int col;
    int val;
    Node *next;
} *first = NULL;

void create(Node *A[])
{
    Node *t;
    int i = 0;
    int k = 0;
    for (i = 0; i < m; i++)
    {
        Node *last = NULL;
        cout << "Enter non-zero elements in row " << i + 1;
        cin >> k;
        while (k--)
        {
            t = new Node;
            cout << "Enter column number and value: ";
            cin >> t->col >> t->val;
            t->next = NULL;
            if (last == NULL)
            {
                last = t;
                A[i] = t;
            }
            else
            {
                last->next = t;
                last = t;
            }
        }
    }
}

void Display(Node *A[])
{
    int i = 0, j = 0;
    for (i = 0; i < m; i++)
    {
        Node *p = A[i];
        for (j = 0; j < n; j++)
        {
            if (p && j == p->col)
            {
                cout << p->val << " ";
                p = p->next;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    Node *A[m];
    create(A);
    Display(A);

    return 0;
}
