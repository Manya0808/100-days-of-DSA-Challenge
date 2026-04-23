#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;  // insert position
}

int main() {
    int n, target;

    // Input size
    scanf("%d", &n);

    int nums[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input target
    scanf("%d", &target);

    int result = searchInsert(nums, n, target);

    printf("%d\n", result);

    return 0;
}