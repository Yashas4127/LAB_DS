#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

typedef struct {
    char items[MAX];
    int top;
} STACK;

void PUSH(STACK *s, char data) {
    s->items[++s->top] = data;
}

char POP(STACK *s) {
    return s->items[s->top--];
}

char PEEK(STACK *s) {
    return s->items[s->top];
}

int preced(char c) {
    switch (c) {
        case '#':
        case ')': return 0;    // after reversing, ) acts like (
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

void reverse(char *exp) {
    int i = 0, j = strlen(exp) - 1;
    char temp;
    while (i < j) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
        i++; j--;
    }
}

int main() {
    STACK s;
    char infix[50], prefix[50], symb, x;
    int i, j = 0;

    s.top = -1;
    PUSH(&s, '#');

    printf("Enter Infix: ");
    scanf("%s", infix);

    reverse(infix);

    // swap brackets
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    for (i = 0; infix[i] != '\0'; i++) {
        symb = infix[i];

        if (isalnum(symb)) {
            prefix[j++] = symb;
        }
        else if (symb == '(') {
            PUSH(&s, symb);
        }
        else if (symb == ')') {
            while (PEEK(&s) != '(')
                prefix[j++] = POP(&s);
            POP(&s);  // pop '('
        }
        else { // operator
            while (preced(symb) < preced(PEEK(&s))) {
                prefix[j++] = POP(&s);
            }
            PUSH(&s, symb);
        }
    }

    while (PEEK(&s) != '#')
        prefix[j++] = POP(&s);

    prefix[j] = '\0';
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
