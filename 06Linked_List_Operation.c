#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

Node* insertEnd(int ele, Node *L) {
    Node *temp = L, *nNode;
    nNode = (Node*)malloc(sizeof(Node));
    if (nNode == NULL) return L;
    nNode->data = ele;
    nNode->next = NULL;

    if (L == NULL) return nNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nNode;
    return L;
}

Node* deleteFront(Node *L) {
    if (L == NULL) return NULL;
    Node *temp = L;
    L = L->next;
    free(temp);
    return L;
}

Node* insertPos(int ele, int pos, Node *L) {
    Node *nNode, *temp = L;
    int i;

    nNode = (Node*)malloc(sizeof(Node));
    if (nNode == NULL) return L;

    nNode->data = ele;

    if (pos == 1) {
        nNode->next = L;
        return nNode;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        free(nNode);
        return L;
    }

    nNode->next = temp->next;
    temp->next = nNode;
    return L;
}

void display(Node *L) {
    Node *temp = L;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* reverse(Node *L) {
    Node *prev = NULL, *curr = L, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node *L = NULL;
    int choice, ele, pos;

    while (1) {
        printf("1. Insert end\n2. Delete front\n3. Insert position\n4. Display\n5. Reverse\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &ele);
                L = insertEnd(ele, L);
                break;
            case 2:
                L = deleteFront(L);
                break;
            case 3:
                scanf("%d", &ele);
                scanf("%d", &pos);
                L = insertPos(ele, pos, L);
                break;
            case 4:
                display(L);
                break;
            case 5:
                L = reverse(L);
                printf("Reversed\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
