#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int Top;
    char *s;
};

int isEmpty(Stack *st)
{
    return st->Top == -1 ? 1 : 0;
}

int isFull(Stack *st)
{
    return st->Top == st->size - 1 ? 1 : 0;
}

void push(Stack *st, char x)
{
    if (isFull(st))
        cout << "Stack Overflow\n";
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}

char pop(Stack *st)
{
    char x = -1;
    if (isEmpty(st))
        cout << "Stack Underflow\n";
    else
    {
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

char stackTop(Stack *st)
{
    return st->Top == -1 ? -1 : st->s[st->Top];
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else
        return 1;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int ExpLength(char *exp)
{
    int len = 0;
    for (int i = 0; exp[i] != '\0'; i++)
        len++;
    return len;
}

char *convert(char *infix)
{
    Stack st;
    st.Top = -1;
    st.size = ExpLength(infix);
    st.s = new char[st.size];

    char *postfix;
    postfix = new char[ExpLength(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(stackTop(&st)))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        }
    }
    while (!isEmpty(&st))
        postfix[j++] = pop(&st);

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter the expression: ";
    cin >> infix;

    char *postfix = convert(&infix[0]);

    cout << postfix << endl;

    return 0;
}