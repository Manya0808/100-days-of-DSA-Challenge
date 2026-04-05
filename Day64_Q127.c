#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];   // adjacency list
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Add edge (undirected)
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph (add reverse edge)
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void bfs(int start) {
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter source vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}