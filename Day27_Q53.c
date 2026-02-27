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

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            ptr2 = ptr2->next;
    }

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, value;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp, *tail1 = NULL, *tail2 = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head1 == NULL) {
            head1 = tail1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head2 == NULL) {
            head2 = tail2 = temp;
        } else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    while (p2 != NULL) {
        p1 = head1;
        while (p1 != NULL) {
            if (p1->data == p2->data) {
                // Connect intersection
                tail2->next = p1;
                break;
            }
            p1 = p1->next;
        }
        if (p1 != NULL)
            break;
        p2 = p2->next;
    }


    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}