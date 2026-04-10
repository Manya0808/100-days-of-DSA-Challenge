#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap Node
typedef struct {
    int vertex, dist;
} HeapNode;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Extract Min
HeapNode extractMin(HeapNode heap[], int* size) {
    HeapNode root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}

// Insert into heap
void insertHeap(HeapNode heap[], int* size, int v, int dist) {
    int i = (*size)++;
    heap[i].vertex = v;
    heap[i].dist = dist;

    // Fix heap
    while (i && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra using Min Heap
void dijkstra(Node* adj[], int n, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    HeapNode heap[MAX];
    int size = 0;

    insertHeap(heap, &size, src, 0);

    while (size > 0) {
        HeapNode minNode = extractMin(heap, &size);
        int u = minNode.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(heap, &size, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int n = 5; // number of nodes

    Node* adj[MAX] = {NULL};

    // Graph edges (u, v, weight)
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 4, 3, 2);
    addEdge(adj, 3, 2, 4);

    int source = 0;

    dijkstra(adj, n, source);

    return 0;
}