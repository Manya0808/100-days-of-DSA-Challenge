#include <stdio.h>
#include <limits.h>

#define MAX 100

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    
    int dist[MAX][MAX];

    // Step 1: Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX / 2;
        }
    }

    // Step 2: Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 4: Find answer
    int resultCity = -1;
    int minCount = INT_MAX;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        if (count <= minCount) {  // tie -> larger index
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}

int main() {
    int n, m, threshold;

    printf("Enter number of cities and edges: ");
    scanf("%d %d", &n, &m);

    int edges[m][3];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Enter distance threshold: ");
    scanf("%d", &threshold);

    int result = findTheCity(n, edges, m, threshold);

    printf("City with smallest neighbors: %d\n", result);

    return 0;
}