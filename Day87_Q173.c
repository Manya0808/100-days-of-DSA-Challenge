#include <stdio.h>

// Function to perform Binary Search (iterative)
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

// Simple Bubble Sort (to match your expected output)
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    sortArray(arr, n);

    // Step 2: Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // OPTIONAL: Binary Search (uncomment if needed)
    /*
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);

    int index = binarySearch(arr, n, target);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    */

    return 0;
}