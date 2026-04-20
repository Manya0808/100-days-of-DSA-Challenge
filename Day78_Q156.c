#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int time = 0;

void dfs(int u, int visited[], int disc[], int low[], int parent[],
         int ap[], int V, int adj[MAX][MAX]) {

    int children = 0;
    visited[u] = 1;

    disc[u] = low[u] = ++time;

    for (int v = 0; v < V; v++) {

        if (adj[u][v] == 0) continue;

        if (!visited[v]) {
            children++;
            parent[v] = u;

            dfs(v, visited, disc, low, parent, ap, V, adj);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Condition 1: Root node
            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            // Condition 2: Non-root
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

void findArticulationPoints(int V, int adj[MAX][MAX]) {

    int visited[MAX] = {0};
    int disc[MAX], low[MAX], parent[MAX];
    int ap[MAX] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, visited, disc, low, parent, ap, V, adj);
    }

    printf("Articulation points: ");
    for (int i = 0; i < V; i++) {
        if (ap[i])
            printf("%d ", i);
    }
}

int main() {
    int V = 5;

    int adj[MAX][MAX] = {
        {0,1,0,0,0},
        {1,0,1,1,1},
        {0,1,0,0,0},
        {0,1,0,0,1},
        {0,1,0,1,0}
    };

    findArticulationPoints(V, adj);

    return 0;
}