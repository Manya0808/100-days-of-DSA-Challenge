#include <stdio.h>
#include <stdbool.h>

bool isToeplitzMatrix(int matrix[100][100], int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;
    int matrix[100][100];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isToeplitzMatrix(matrix, rows, cols)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
