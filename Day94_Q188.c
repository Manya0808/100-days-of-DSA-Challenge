#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001] = {0};

    // Count frequency
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int* result = (int*)malloc(arr1Size * sizeof(int));
    int index = 0;

    // Arrange according to arr2
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Remaining elements in ascending order
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return result;
}

int main() {
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int returnSize;

    int* result = relativeSortArray(arr1, n, arr2, m, &returnSize);

    printf("Sorted Array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}