#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= maxTime) {
            currentSum += boards[i];
        } else {
            painters++;
            currentSum = boards[i];

            if (painters > k) return 0; 
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int left = boards[0], right = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > left) left = boards[i];
        right += boards[i];
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            right = mid - 1; // try smaller time
        } else {
            left = mid + 1; // increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int ans = minTime(boards, n, k);
    printf("Minimum time required: %d\n", ans);

    return 0;
}