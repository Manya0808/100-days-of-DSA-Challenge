#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neigh = adj[node][i];

        if (!visited[neigh]) {
            if (dfs(neigh, adj, adjSize, visited, recStack))
                return true;
        } else if (recStack[neigh]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0;
    return false;
}

// Main logic
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize) {
    
    // Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    // Check for cycle
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                return false;
            }
        }
    }

    return true;
}

// Driver code (MAIN FUNCTION)
int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &prerequisitesSize);

    int** prerequisites = (int**)malloc(prerequisitesSize * sizeof(int*));

    printf("Enter pairs (a b) meaning b -> a:\n");
    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    if (canFinish(numCourses, prerequisites, prerequisitesSize)) {
        printf("YES, you can finish all courses\n");
    } else {
        printf("NO, cycle detected\n");
    }

    return 0;
}