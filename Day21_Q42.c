#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value;
    scanf("%d", &n);

    if(n <= 0) return 0;

    scanf("%d", &value);
    struct ListNode* head = createNode(value);
    struct ListNode* temp = head;
    for(int i = 1; i < n; i++) {
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }

    struct ListNode* mid = middleNode(head);

   
    while(mid != NULL) {
        printf("%d ", mid->val);
        mid = mid->next;
    }

    return 0;
}