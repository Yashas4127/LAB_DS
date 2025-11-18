#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 50

char queue[MAX][LEN];
int front = 0, rear = -1;

void insert(char str[]) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    rear++;
    strcpy(queue[rear], str);
}

void delete() {
    if (front > rear) {
        printf("Underflow\n");
        return;
    }
    front++;
}

void display() {
    if (front > rear) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%s\n", queue[i]);
}

int main() {
    int choice;
    char str[LEN];

    while (1) {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", str);
                insert(str);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
