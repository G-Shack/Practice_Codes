#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(Stack *st)
{
    cout << "Enter Size: ";
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void Display(Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.S[i] << " ";
    }
    cout << endl;
}

void push(Stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow\n";
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        cout << "Invalid Position!";
    else
        x = st.S[st.top - index + 1];

    return x;
}

int isFull(Stack st)
{
    return st.top == st.size - 1;
}

int isEmpty(Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int StackTop(Stack st)
{
    if (!isEmpty)
        return st.S[st.top];
    return -1;
}

int main()
{
    Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    cout << pop(&st) << endl;
    Display(st);

    return 0;
}