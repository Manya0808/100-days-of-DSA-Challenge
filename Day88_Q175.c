#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// check if we can place k cows with at least 'dist' gap
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // first cow placed
    int last = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
            if (count >= k)
                return 1;
        }
    }
    return 0;
}

int maxMinDistance(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;        // valid distance
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;   // try smaller
        }
    }
    return ans;
}

int main() {
    int n, k;

    // Input
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Output
    int result = maxMinDistance(stalls, n, k);
    printf("%d\n", result);

    return 0;
}