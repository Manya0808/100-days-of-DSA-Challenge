#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// check if we can place m balls with given minimum distance
int canPlace(int position[], int n, int m, int dist) {
    int count = 1;  // first ball placed
    int last = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
            if (count >= m)
                return 1;
        }
    }
    return 0;
}

int maxDistance(int position[], int n, int m) {
    qsort(position, n, sizeof(int), compare);

    int low = 1;
    int high = position[n - 1] - position[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, n, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;

    // Input
    printf("Enter number of positions: ");
    scanf("%d", &n);

    int position[n];
    printf("Enter positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter number of balls (m): ");
    scanf("%d", &m);

    // Output
    int result = maxDistance(position, n, m);
    printf("Maximum minimum distance: %d\n", result);

    return 0;
}