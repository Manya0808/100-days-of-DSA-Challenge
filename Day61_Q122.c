#include <stdio.h>
#include <stdlib.h>

void dfs(int** isConnected, int n, int* visited, int city) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}

int main() {
    int n = 3;

    // allocate matrix
    int** isConnected = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        isConnected[i] = (int*)malloc(n * sizeof(int));
    }

    // input example
    int data[3][3] = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    // copy data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            isConnected[i][j] = data[i][j];
        }
    }

    int result = findCircleNum(isConnected, n);
    printf("Number of Provinces: %d\n", result);

    // free memory
    for (int i = 0; i < n; i++) {
        free(isConnected[i]);
    }
    free(isConnected);

    return 0;
}