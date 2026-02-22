#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};


struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("\nReversed List: ");
    printList(head);

    return 0;
}