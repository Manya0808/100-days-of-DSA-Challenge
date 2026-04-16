#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int i = 0; i < graphSize; i++) {
        if (color[i] != -1) continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                } else if (color[neighbor] == color[node]) {
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}

// MAIN FUNCTION FOR TESTING
int main() {
    int graphSize = 4;

    // Example: [[1,3],[0,2],[1,3],[0,2]]
    int colSize[] = {2, 2, 2, 2};

    int** graph = (int**)malloc(graphSize * sizeof(int*));

    graph[0] = (int[]){1, 3};
    graph[1] = (int[]){0, 2};
    graph[2] = (int[]){1, 3};
    graph[3] = (int[]){0, 2};

    if (isBipartite(graph, graphSize, colSize))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    free(graph);
    return 0;
}