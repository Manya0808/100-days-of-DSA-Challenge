#include <stdio.h>

#define MAX 100

// DFS function
int dfs(int node, int parent, int visited[], int adj[MAX][MAX], int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, visited, adj, V))
                    return 1;
            }
            else if (i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

// Function to check cycle
int isCycle(int V, int adj[MAX][MAX]) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, V))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}