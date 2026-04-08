#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize) {
    
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    int* indegree = (int*)calloc(numCourses, sizeof(int));

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    // Queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    if (count != numCourses) {
        printf("Cycle detected! No valid order.\n");
        return NULL;
    }

    return result;
}

int main() {
    int numCourses, m;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &m);

    int** prerequisites = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter prerequisites (a b means b -> a):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    int* order = findOrder(numCourses, prerequisites, m);

    if (order != NULL) {
        printf("Course Order: ");
        for (int i = 0; i < numCourses; i++) {
            printf("%d ", order[i]);
        }
    }

    return 0;
}