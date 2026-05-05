#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int n) {
    if (n < 2) return 0;

    int min = INT_MAX, max = INT_MIN;

    // Step 1: Find min and max
    for (int i = 0; i < n; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    if (min == max) return 0;

    // Step 2: Create buckets
    int bucketSize = (max - min) / (n - 1);
    if ((max - min) % (n - 1) != 0) bucketSize++;

    int bucketCount = (max - min) / bucketSize + 1;

    int *bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int *bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int *used = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
        used[i] = 0;
    }

    // Step 3: Fill buckets
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - min) / bucketSize;

        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
        used[idx] = 1;
    }

    // Step 4: Find max gap
    int prev = min;
    int maxGap = 0;

    for (int i = 0; i < bucketCount; i++) {
        if (!used[i]) continue;

        int gap = bucketMin[i] - prev;
        if (gap > maxGap) maxGap = gap;

        prev = bucketMax[i];
    }

    // Free memory
    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}

int main() {
    int nums[] = {3, 6, 9, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maximumGap(nums, n);
    printf("Maximum Gap: %d\n", result);

    return 0;
}