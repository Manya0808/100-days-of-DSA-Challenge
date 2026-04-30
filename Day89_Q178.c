#include <stdio.h>

// Function to check if shipping is possible within given days
int canShip(int weights[], int size, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < size; i++) {
        if (currentLoad + weights[i] > capacity) {
            requiredDays++;
            currentLoad = 0;
        }
        currentLoad += weights[i];
    }

    return requiredDays <= days;
}

// Main function to find minimum capacity
int shipWithinDays(int weights[], int size, int days) {
    int left = 0, right = 0;

    // Find max weight and total sum
    for (int i = 0; i < size; i++) {
        if (weights[i] > left)
            left = weights[i];
        right += weights[i];
    }

    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, size, days, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, days;

    // Input
    printf("Enter number of packages: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter number of days: ");
    scanf("%d", &days);

    // Output
    int result = shipWithinDays(weights, n, days);
    printf("Minimum capacity required: %d\n", result);

    return 0;
}