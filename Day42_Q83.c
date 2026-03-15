#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0, rear = -1;
int stack[MAX];
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {

    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        enqueue(x);
    }

    while(front <= rear) {
        push(dequeue());
    }

    while(top != -1) {
        enqueue(pop());
    }

    printf("Reversed Queue:\n");

    for(int i=front;i<=rear;i++) {
        printf("%d ",queue[i]);
    }

    return 0;
}