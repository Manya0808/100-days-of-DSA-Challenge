#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

int main() {

    struct Node* l1 = (struct Node*)malloc(sizeof(struct Node));
    l1->val = 2;
    l1->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->val = 4;
    l1->next->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct Node* l2 = (struct Node*)malloc(sizeof(struct Node));
    l2->val = 5;
    l2->next = (struct Node*)malloc(sizeof(struct Node));
    l2->next->val = 6;
    l2->next->next = (struct Node*)malloc(sizeof(struct Node));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct Node* head = NULL;
    struct Node* temp = NULL;
    int carry = 0;

    // Add both lists
    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = sum % 10;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print result
    printf("Result: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}