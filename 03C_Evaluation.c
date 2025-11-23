#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// -----------------------------------
// Evaluate operator
// -----------------------------------
float eval(float op1, float op2, char op)
{
    switch (op)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0)
            {
                printf("Division by 0 error!\n");
                exit(1);
            }
            return op1 / op2;

        case '%':
            if (op2 == 0)
            {
                printf("Division by 0 error!\n");
                exit(1);
            }
            return fmod(op1, op2);

        case '^': return pow(op1, op2);
    }
    printf("Invalid operator!\n");
    exit(1);
}

// -----------------------------------
// POSTFIX Evaluation
// -----------------------------------
float evaluatePostfix(char postfix[])
{
    float stack[100], smalTab[26], bigTab[26];
    int top = -1, i = 0, j;
    char sym;

    for (int k = 0; k < 26; k++)
    {
        smalTab[k] = -999;
        bigTab[k] = -999;
    }

    while ((sym = postfix[i]) != '\0')
    {
        if (sym==' ' || sym=='\n' || sym=='\t' || sym=='\r')
        {
            i++;
            continue;
        }

        if (sym >= '0' && sym <= '9')
        {
            stack[++top] = sym - '0';
        }
        else if (sym >= 'a' && sym <= 'z')
        {
            j = sym - 'a';
            if (smalTab[j] == -999)
            {
                printf("Enter value of %c: ", sym);
                scanf("%f", &smalTab[j]);
            }
            stack[++top] = smalTab[j];
        }
        else if (sym >= 'A' && sym <= 'Z')
        {
            j = sym - 'A';
            if (bigTab[j] == -999)
            {
                printf("Enter value of %c: ", sym);
                scanf("%f", &bigTab[j]);
            }
            stack[++top] = bigTab[j];
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid postfix expression!\n");
                exit(1);
            }
            float op2 = stack[top--];
            float op1 = stack[top--];
            float val = eval(op1, op2, sym);
            stack[++top] = val;
        }

        i++;
    }

    if (top == 0) return stack[top];

    printf("Invalid postfix expression!\n");
    exit(1);
}

// -----------------------------------
// PREFIX Evaluation
// -----------------------------------
float evaluatePrefix(char prefix[])
{
    float stack[100], smalTab[26], bigTab[26];
    int top = -1, j;
    char sym;

    for (int k = 0; k < 26; k++)
    {
        smalTab[k] = -999;
        bigTab[k] = -999;
    }

    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        sym = prefix[i];

        if (sym==' ' || sym=='\n' || sym=='\t' || sym=='\r')
            continue;

        if (sym >= '0' && sym <= '9')
        {
            stack[++top] = sym - '0';
        }
        else if (sym >= 'a' && sym <= 'z')
        {
            j = sym - 'a';
            if (smalTab[j] == -999)
            {
                printf("Enter value of %c: ", sym);
                scanf("%f", &smalTab[j]);
            }
            stack[++top] = smalTab[j];
        }
        else if (sym >= 'A' && sym <= 'Z')
        {
            j = sym - 'A';
            if (bigTab[j] == -999)
            {
                printf("Enter value of %c: ", sym);
                scanf("%f", &bigTab[j]);
            }
            stack[++top] = bigTab[j];
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid prefix expression!\n");
                exit(1);
            }

            float op1 = stack[top--];
            float op2 = stack[top--];

            float val = eval(op1, op2, sym);
            stack[++top] = val;
        }
    }

    if (top == 0) return stack[top];

    printf("Invalid prefix expression!\n");
    exit(1);
}

// -----------------------------------
// MAIN PROGRAM – Both Evaluators
// -----------------------------------
int main()
{
    char expr[100];
    int choice;
    float result;

    printf("\n--- Combined Prefix & Postfix Evaluation Program ---\n");
    printf("1. Evaluate Postfix\n");
    printf("2. Evaluate Prefix\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    getchar();  // remove leftover newline

    printf("Enter expression:\n");
    fgets(expr, 100, stdin);

    if (choice == 1)
    {
        result = evaluatePostfix(expr);
        printf("Postfix Result = %.2f\n", result);
    }
    else if (choice == 2)
    {
        result = evaluatePrefix(expr);
        printf("Prefix Result = %.2f\n", result);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
