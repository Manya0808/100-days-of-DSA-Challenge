#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

void merge(Element arr[], Element temp[], int left, int mid, int right, int count[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightSmaller = 0;

    while (i <= mid && j <= right) {
// Right element is smaller
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightSmaller++;
        }
        else {
            
            count[arr[i].index] += rightSmaller;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightSmaller;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Element arr[], Element temp[], int left, int right, int count[]) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, left, mid, count);
    mergeSort(arr, temp, mid + 1, right, count);

    merge(arr, temp, left, mid, right, count);
}

int main() {

    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Element arr[n], temp[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    printf("Count of smaller elements on right side:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}