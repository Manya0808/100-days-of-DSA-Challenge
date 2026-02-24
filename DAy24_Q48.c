#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, val, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);

        struct ListNode* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter value to remove: ");
    scanf("%d", &val);

    head = removeElements(head, val);

    printf("Updated List: ");
    printList(head);

    return 0;
}