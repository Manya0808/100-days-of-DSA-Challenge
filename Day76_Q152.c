#include <stdio.h>
#include <stdlib.h>

#define MAX 101

// Node definition
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Visited map
struct Node* visited[MAX];

// DFS clone
struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) return NULL;

    for (int i = 0; i < MAX; i++)
        visited[i] = NULL;

    return dfs(s);
}

// Helper: Create Node
struct Node* createNode(int val, int numNeighbors) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = numNeighbors;
    node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * numNeighbors);
    return node;
}

// Print graph (DFS)
void printGraph(struct Node* node, int visitedPrint[]) {
    if (!node || visitedPrint[node->val]) return;

    visitedPrint[node->val] = 1;

    printf("Node %d -> ", node->val);
    for (int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");

    for (int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i], visitedPrint);
    }
}

int main() {
    // Create graph manually
    struct Node* node1 = createNode(1, 2);
    struct Node* node2 = createNode(2, 2);
    struct Node* node3 = createNode(3, 2);
    struct Node* node4 = createNode(4, 2);

    // Connect nodes (undirected)
    node1->neighbors[0] = node2;
    node1->neighbors[1] = node4;

    node2->neighbors[0] = node1;
    node2->neighbors[1] = node3;

    node3->neighbors[0] = node2;
    node3->neighbors[1] = node4;

    node4->neighbors[0] = node1;
    node4->neighbors[1] = node3;

    printf("Original Graph:\n");
    int visitedPrint[MAX] = {0};
    printGraph(node1, visitedPrint);

    struct Node* cloned = cloneGraph(node1);

    printf("\nCloned Graph:\n");
    for (int i = 0; i < MAX; i++) visitedPrint[i] = 0;
    printGraph(cloned, visitedPrint);

    return 0;
}