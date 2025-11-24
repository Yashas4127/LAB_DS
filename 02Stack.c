#include <stdio.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} STACK;

// Initialize stack
void init(STACK *s) {
    s->top = -1;
}

// Push
void push(STACK *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = val;
}

// Pop
int pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[s->top--];
}

// Display stack
void display(STACK *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top → bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->items[i]);
    printf("\n");
}

/* ------------------------------------
   Check if STACK ELEMENTS form palindrome
------------------------------------- */
int isStackPalindrome(STACK *s) {
    if (s->top == -1) return 1; // empty = palindrome

    int i = 0, j = s->top;

    // Compare items like checking array palindrome
    while (i < j) {
        if (s->items[i] != s->items[j])
            return 0;  // Not palindrome
        i++;
        j--;
    }
    return 1;  // Palindrome
}

int main() {
    STACK s;
    init(&s);

    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if STACK is Palindrome\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&s, val);
                break;

            case 2:
                val = pop(&s);
                if (val != -1)
                    printf("Popped: %d\n", val);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                if (isStackPalindrome(&s))
                    printf("STACK is a Palindrome.\n");
                else
                    printf("STACK is NOT a Palindrome.\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}