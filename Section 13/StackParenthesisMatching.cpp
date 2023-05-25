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
    if (st->Top == st->size - 1)
        return 1;
    else
        return 0;
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

int ExpLength(char *exp)
{
    int len = 0;
    for (int i = 0; exp[i] != '\0'; i++)
        len++;
    return len;
}

int isBalanced(char *exp)
{
    Stack st;
    int i = 0;
    st.size = ExpLength(exp);
    st.Top = -1;
    st.s = new char[st.size];
    char x;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&st, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(&st))
                return -1;
            x = pop(&st);
            if ((exp[i] == ')' && x == '(') || (exp[i] == '}' && x == '{') || (exp[i] == ']' && x == '['))
                continue;
            else
                return -1;
        }
    }
    return isEmpty(&st) ? 0 : -1;
}

int main()
{
    string exp;
    cout << "Enter the expression: ";
    cin >> exp;
    int result = isBalanced(&exp[0]);
    if (result == 0)
        cout << "Expression has balanced parenthesis" << endl;
    else
        cout << "Parenthesis imbalanced" << endl;
    return 0;
}