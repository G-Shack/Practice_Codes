#include <iostream>
#include "Queue.h"
#ifndef Stack_h
#define Stack_h

using namespace std;

struct Stack
{
    int size;
    int top;
    Node **S;
};

void Stackcreate(Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node *[st->size];
}

void push(Stack *st, Node *x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Node *pop(Stack *st)
{
    Node *x = NULL;

    if (st->top == -1)
        cout << "Stack Underflow\n";
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFullStack(Stack st)
{
    return st.top == st.size - 1;
}

#endif