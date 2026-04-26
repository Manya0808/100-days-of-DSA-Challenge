#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = findMin(nums, n);

    printf("Minimum element: %d\n", result);

    return 0;
}