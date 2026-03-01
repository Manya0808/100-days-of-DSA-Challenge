#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k;

    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int length = 1;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}