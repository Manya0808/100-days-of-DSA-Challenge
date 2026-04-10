#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

// Queue functions
void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (adj[u][v] == 0) {  // avoid duplicate edge
            adj[u][v] = 1;
            indegree[v]++;
        }
    }

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX];
    int idx = 0;

    // Kahn's Algorithm
    while (!isEmpty()) {
        int node = dequeue();
        topo[idx++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Check for cycle
    if (idx != n) {
        printf("Cycle exists! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < idx; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}