#include <stdio.h>

int findPeakElement(int nums[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int peakIndex = findPeakElement(nums, n);

    printf("Peak element index: %d\n", peakIndex);
    printf("Peak element value: %d\n", nums[peakIndex]);

    return 0;
}