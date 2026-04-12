#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int** points, int n) {
    int* minDist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        minDist[i] = INT_MAX;

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        visited[u] = 1;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                if (dist < minDist[v])
                    minDist[v] = dist;
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}

int main() {
    int n;

    printf("Enter number of points: ");
    scanf("%d", &n);

    // Allocate 2D array
    int** points = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);

    printf("Minimum Cost = %d\n", result);

    // Free memory
    for (int i = 0; i < n; i++)
        free(points[i]);
    free(points);

    return 0;
}