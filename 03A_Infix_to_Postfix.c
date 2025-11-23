#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 25

typedef struct
{
    char items[MAXSIZE];
    int top;
} STACK;

void PUSH(STACK *s, char data)
{
    s->items[++s->top] = data;
}

char POP(STACK *s)
{
    return s->items[s->top--];
}

char PEEK(STACK *s)
{
    return s->items[s->top];
}

int preced(char symb)
{
    switch (symb)
    {
    case '#':
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int main()
{
    STACK s;
    char infix[30], postfix[30], symb;
    int i, j = 0;

    s.top = -1;
    PUSH(&s, '#');

    printf("Enter infix expression : ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i];

        if (isalnum(symb))
            postfix[j++] = symb;

        else if (symb == '(')
            PUSH(&s, symb);

        else if (symb == ')')
        {
            char x = POP(&s);
            while (x != '(')
            {
                postfix[j++] = x;
                x = POP(&s);
            }
        }

        else
        {
            while (preced(symb) <= preced(PEEK(&s)))
            {
                postfix[j++] = POP(&s);
            }
            PUSH(&s, symb);
        }
    }

    while (PEEK(&s) != '#')
        postfix[j++] = POP(&s);

    postfix[j] = '\0';

    printf("\nPostfix expression = %s\n", postfix);

    return 0;
}
