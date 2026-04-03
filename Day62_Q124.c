#include <stdio.h>
#include <stdlib.h>

// DFS function
void dfs(int** rooms, int* roomsColSize, int* visited, int room) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];

        if (!visited[next]) {
            dfs(rooms, roomsColSize, visited, next);
        }
    }
}

// Main logic
int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* visited = (int*)calloc(roomsSize, sizeof(int));

    dfs(rooms, roomsColSize, visited, 0);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return 0; // false
        }
    }

    free(visited);
    return 1; // true
}

int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    // Allocate rooms
    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    // Input keys for each room
    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));

        printf("Enter keys: ");
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    int result = canVisitAllRooms(rooms, n, roomsColSize);

    if (result)
        printf("True: All rooms can be visited\n");
    else
        printf("False: Cannot visit all rooms\n");

    // Free memory
    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }
    free(rooms);
    free(roomsColSize);

    return 0;
}