#include <stdio.h>

#define MAX 100

void dfs(int image[MAX][MAX], int rows, int cols, int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    // If color doesn't match, stop
    if (image[r][c] != oldColor)
        return;

    // Change color
    image[r][c] = newColor;

    // 4 directions
    dfs(image, rows, cols, r + 1, c, oldColor, newColor);
    dfs(image, rows, cols, r - 1, c, oldColor, newColor);
    dfs(image, rows, cols, r, c + 1, oldColor, newColor);
    dfs(image, rows, cols, r, c - 1, oldColor, newColor);
}

int main() {
    int rows, cols;
    int image[MAX][MAX];

    // Input size
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix
    printf("Enter the image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, newColor;

    // Input starting point and new color
    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &newColor);

    int oldColor = image[sr][sc];

    // If same color, no need to process
    if (oldColor != newColor) {
        dfs(image, rows, cols, sr, sc, oldColor, newColor);
    }

    // Output result
    printf("Updated Image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
