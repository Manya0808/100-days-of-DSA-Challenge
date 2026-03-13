#include <stdio.h>

void dailyTemperatures(int temps[], int n, int result[]) {
    int stack[n];   
    int top = -1;   

    for (int i = 0; i < n; i++) {

        while (top >= 0 && temps[i] > temps[stack[top]]) {
            int idx = stack[top];
            top--;
            result[idx] = i - idx;
        }

        stack[++top] = i;
    }

    while (top >= 0) {
        result[stack[top--]] = 0;
    }
}

int main() {
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int temps[n];
    int result[n];

    printf("Enter temperatures:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &temps[i]);
    }

    dailyTemperatures(temps, n, result);

    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}