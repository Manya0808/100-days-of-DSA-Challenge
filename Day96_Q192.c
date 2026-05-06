#include <stdio.h>
#include <stdlib.h>

// Merge function to count reverse pairs and sort
int merge(int* nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge step
    int n = right - left + 1;
    int* temp = (int*)malloc(n * sizeof(int));

    int i = left, k = 0;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Copy back
    for (int p = 0; p < n; p++) {
        nums[left + p] = temp[p];
    }

    free(temp);
    return count;
}

// Merge sort function
int mergeSort(int* nums, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = 0;

    count += mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);

    return count;
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = mergeSort(nums, 0, n - 1);

    printf("Number of reverse pairs: %d\n", result);

    free(nums);
    return 0;
}