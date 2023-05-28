#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int Top;
    int *s;
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

int Evaluate(char *postfix)
{
    Stack st;
    st.Top = -1;
    st.size = ExpLength(postfix);
    st.s = new int[st.size];
    int x1, x2, i = 0, r = 0;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(&st, postfix[i] - '0');
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
            {
                r = x1 + x2;
                push(&st, r);
                break;
            }
            case '-':
            {
                r = x1 - x2;
                push(&st, r);
                break;
            }
            case '*':
            {
                r = x1 * x2;
                push(&st, r);
                break;
            }
            case '/':
            {
                r = x1 / x2;
                push(&st, r);
                break;
            }

            default:
                break;
            }
        }
    }
    return pop(&st);
}

int main()
{
    string postfix;
    cout << "Enter the expression: ";
    cin >> postfix;

    int x = Evaluate(&postfix[0]);
    cout << "Evaluation is " << x << endl;
    return 0;
}