#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void checkPalindrome() {
    if (top == -1) {
        printf("Empty\n");
        return;
    }
    int i = 0, j = top, flag = 1;
    while (i < j) {
        if (stack[i] != stack[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }
    if (flag) printf("Palindrome\n");
    else printf("Not Palindrome\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("1.Push\n2.Pop\n3.Display\n4.Check Palindrome\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                checkPalindrome();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
