#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create array of adjacency lists
    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));

    // Initialize all lists as empty
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    int u, v;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // For UNDIRECTED graph (important)
        struct Node* newNode2 = createNode(u);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adjList[i];

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* temp = adjList[i];
        while (temp != NULL) {
            struct Node* next = temp;
            temp = temp->next;
            free(next);
        }
    }
    free(adjList);

    return 0;
}