#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int timer = 0;

int graph[MAX][MAX];
int graphSize[MAX];

int disc[MAX], low[MAX], visited[MAX];

// DFS
void dfs(int u, int parent, int n) {
    visited[u] = 1;
    disc[u] = low[u] = timer++;

    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u, n);

            if (low[v] < low[u])
                low[u] = low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                printf("Critical Connection: %d - %d\n", u, v);
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        graphSize[i] = 0;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    // Run DFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, n);
        }
    }

    return 0;
}