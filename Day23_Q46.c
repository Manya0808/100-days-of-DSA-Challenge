#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = 
        (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    
    
    struct ListNode* head = createNode(3);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(0);
    struct ListNode* fourth = createNode(-4);

    
    head->next = second;
    second->next = third;
    third->next = fourth;

    fourth->next = second;  

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}