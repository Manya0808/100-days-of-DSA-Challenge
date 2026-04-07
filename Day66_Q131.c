#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neigh = adj[node][i];

        if (!visited[neigh]) {
            if (dfs(neigh, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neigh]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // backtrack
    return false;
}

// Function to detect cycle
bool hasCycle(int n, int** adj, int* adjSize) {
    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter directed edges (u v means u -> v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    if (hasCycle(n, adj, adjSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}