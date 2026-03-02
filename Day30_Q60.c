#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    int carry = 0;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    while (l1 != NULL || l2 != NULL || carry) {
        
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        struct ListNode* newNode = createNode(sum % 10);
        carry = sum / 10;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return reverse(head);
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n1, n2, value;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* temp;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    
    printf("Enter elements: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        struct ListNode* newNode = createNode(value);
        
        if (l1 == NULL) {
            l1 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    
    printf("Enter elements: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        struct ListNode* newNode = createNode(value);
        
        if (l2 == NULL) {
            l2 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printf("Result: ");
    printList(result);

    return 0;
}