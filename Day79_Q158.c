#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX], top = -1;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// First DFS (fill stack)
void dfs1(int v, int visited[], int adj[MAX][MAX], int V) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs1(i, visited, adj, V);
        }
    }

    push(v);
}

// Second DFS (on reversed graph)
void dfs2(int v, int visited[], int rev[MAX][MAX], int V) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (rev[v][i] && !visited[i]) {
            dfs2(i, visited, rev, V);
        }
    }
}

int main() {
    int V = 5, E = 5;

    int edges[5][2] = {
        {0, 2}, {0, 3}, {1, 0}, {2, 1}, {3, 4}
    };

    int adj[MAX][MAX] = {0};
    int rev[MAX][MAX] = {0};

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        rev[v][u] = 1; // reverse edge
    }

    int visited[MAX] = {0};

    // Step 1: fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, visited, adj, V);
        }
    }

    // Reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int sccCount = 0;

    // Step 2 & 3: process stack
    while (top != -1) {
        int v = pop();

        if (!visited[v]) {
            dfs2(v, visited, rev, V);
            sccCount++;
        }
    }

    printf("%d\n", sccCount);

    return 0;
}