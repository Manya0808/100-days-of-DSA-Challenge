#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->stack[++s->top] = val;

    if (s->minTop == -1 || val <= s->minStack[s->minTop]) {
        s->minStack[++s->minTop] = val;
    }
}

void pop(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    if (s->stack[s->top] == s->minStack[s->minTop]) {
        s->minTop--;
    }

    s->top--;
}

int top(MinStack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}

int getMin(MinStack *s) {
    if (s->minTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    int choice, value;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Top\n4.GetMin\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                printf("Top: %d\n", top(&s));
                break;

            case 4:
                printf("Minimum: %d\n", getMin(&s));
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}