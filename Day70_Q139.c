#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(int n, int m, Edge edges[], int src) {
    int dist[n];

    // Step 1: Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Step 2: Relax edges (n-1) times
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE DETECTED\n");
            return;
        }
    }

    // Step 4: Print distances
    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n = 5;  // vertices
    int m = 8;  // edges

    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0;

    bellmanFord(n, m, edges, src);

    return 0;
}