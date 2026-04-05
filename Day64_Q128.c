#include <stdio.h>

typedef struct {
    int x, y;
} Node;

int orangesRotting(int grid[100][100], int rows, int cols) {
    Node queue[10000];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Add rotten oranges to queue & count fresh
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int minutes = 0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // Step 2: BFS
    while (front < rear) {
        int size = rear - front;
        int changed = 0;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dirs[d][0];
                int ny = curr.y + dirs[d][1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Node){nx, ny};
                    fresh--;
                    changed = 1;
                }
            }
        }

        if (changed) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int rows, cols;
    
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int grid[100][100];

    printf("Enter grid (0-empty, 1-fresh, 2-rotten):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, cols);

    printf("Minimum minutes: %d\n", result);

    return 0;
}