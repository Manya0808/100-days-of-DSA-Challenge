#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    int n, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Empty list\n");
        return 0;
    }

    struct ListNode *head = NULL, *temp = NULL, *cycleNode = NULL;

    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct ListNode* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }

        if (i == 0)
            cycleNode = head;
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos >= 0) {
        temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        struct ListNode* tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        tail->next = temp;  
    }
    struct ListNode* result = detectCycle(head);

    if (result == NULL)
        printf("No cycle\n");
    else
        printf("Cycle starts at node with value: %d\n", result->val);

    return 0;
}