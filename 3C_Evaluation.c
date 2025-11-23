#include <stdio.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    float items[MAX];
    int top;
} STACK;

void PUSH(STACK *s, float val) {
    s->items[++s->top] = val;
}

float POP(STACK *s) {
    return s->items[s->top--];
}

// Compute function
float compute(float n1, char op, float n2) {
    switch (op) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return n1 / n2;
        case '^': {
            float pow = 1;
            for (int i = 0; i < (int)n2; i++)
                pow *= n1;
            return pow;
        }
    }
    return 0;
}

int main() {
    STACK s;
    s.top = -1;

    char postfix[30], symb;
    float n1, n2, val, data;

    printf("Enter a valid postfix expression:\n");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        symb = postfix[i];

        if (isdigit(symb)) {
            PUSH(&s, symb - '0');
        }
        else if (isalpha(symb)) {
            printf("Enter value for %c: ", symb);
            scanf("%f", &data);
            PUSH(&s, data);
        }
        else {
            n2 = POP(&s);
            n1 = POP(&s);
            val = compute(n1, symb, n2);
            PUSH(&s, val);
        }
    }

    printf("Result of evaluation: %f\n", POP(&s));
    return 0;
}



#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    float items[MAX];
    int top;
} STACK;

void PUSH(STACK *s, float v) {
    s->items[++s->top] = v;
}

float POP(STACK *s) {
    return s->items[s->top--];
}

// Compute
float compute(float n1, char op, float n2) {
    switch (op) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return n1 / n2;
        case '^': {
            float p = 1;
            for (int i = 0; i < (int)n2; i++)
                p *= n1;
            return p;
        }
    }
    return 0;
}

int main() {
    STACK s;
    s.top = -1;

    char prefix[30], symb;
    float n1, n2, val, data;

    printf("Enter a valid prefix expression:\n");
    scanf("%s", prefix);

    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        symb = prefix[i];

        if (isdigit(symb)) {
            PUSH(&s, symb - '0');
        }
        else if (isalpha(symb)) {
            printf("Enter value for %c: ", symb);
            scanf("%f", &data);
            PUSH(&s, data);
        }
        else {  // operator
            n1 = POP(&s);
            n2 = POP(&s);
            val = compute(n1, symb, n2);
            PUSH(&s, val);
        }
    }

    printf("Result of evaluation: %f\n", POP(&s));
    return 0;
}
