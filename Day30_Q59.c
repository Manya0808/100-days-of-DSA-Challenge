#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    printf("Polynomial: ");
    printPolynomial(head);

    freeList(head);
    return 0;
}