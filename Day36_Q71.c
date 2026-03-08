#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // number of elements
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    int front = 0, rear = -1;

    // enqueue elements
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        rear = (rear + 1) % n;
        queue[rear] = val;
    }

    // number of dequeue operations
    scanf("%d", &m);

    // dequeue operations
    for(int i = 0; i < m; i++) {
        front = (front + 1) % n;
    }

    // display queue from front to rear
    int count = n;
    for(int i = 0; i < count; i++) {
        int index = (front + i) % n;
        printf("%d ", queue[index]);
    }

    free(queue);
    return 0;
}