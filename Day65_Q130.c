#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int node;
    int parent;
} Pair;

Pair queue[MAX];
int front = -1, rear = -1;

void enqueue(int node, int parent) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear].node = node;
    queue[rear].parent = parent;
}

Pair dequeue() {
    Pair p = queue[front];
    front++;
    if (front > rear) front = rear = -1;
    return p;
}

int isEmpty() {
    return front == -1;
}

// BFS to detect cycle
int bfs(int start, int adj[MAX][MAX], int visited[], int V) {
    enqueue(start, -1);
    visited[start] = 1;

    while (!isEmpty()) {
        Pair p = dequeue();
        int node = p.node;
        int parent = p.parent;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    enqueue(i, node);
                }
                else if (i != parent) {
                    return 1; // cycle found
                }
            }
        }
    }
    return 0;
}

// Main function
int isCycle(int V, int adj[MAX][MAX]) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited, V)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    if (isCycle(V, adj))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}