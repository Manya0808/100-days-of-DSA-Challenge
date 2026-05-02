#include <stdio.h>

// Function to check if we can split into <= k subarrays
int canSplit(int nums[], int n, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            subarrays++;
            currentSum = nums[i];

            if (subarrays > k) return 0; // Not possible
        }
    }
    return 1;
}

// Main function to find minimized largest sum
int splitArray(int nums[], int n, int k) {
    int left = nums[0], right = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i++) {
        if (nums[i] > left) left = nums[i];
        right += nums[i];
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, n, k, mid)) {
            result = mid;
            right = mid - 1; // Try smaller
        } else {
            left = mid + 1; // Increase limit
        }
    }

    return result;
}

// Driver code
int main() {
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int ans = splitArray(nums, n, k);
    printf("Minimum largest sum: %d\n", ans);

    return 0;
}
