#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py)
        parent[px] = py;
}

int* findRedundantConnection(int edges[][2], int edgesSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));

    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = u;
            result[1] = v;
            return result;
        }

        unionSet(parent, u, v);
    }

    return NULL;
}

int main() {
    int n;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int* res = findRedundantConnection(edges, n);

    if (res != NULL)
        printf("Redundant Edge: [%d, %d]\n", res[0], res[1]);
    else
        printf("No redundant edge found\n");

    return 0;
}