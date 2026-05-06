#include <stdio.h>
#include <stdlib.h>

// Merge function to count inversions
int merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int inv_count = 0;

    int n = right - left + 1;
    int* temp = (int*)malloc(n * sizeof(int));

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // KEY LINE
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back
    for (int p = 0; p < n; p++) {
        arr[left + p] = temp[p];
    }

    free(temp);
    return inv_count;
}

// Merge Sort function
int mergeSort(int arr[], int left, int right) {
    int inv_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = mergeSort(arr, 0, n - 1);

    printf("Number of inversions: %d\n", result);

    free(arr);
    return 0;
}