#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], Pair temp[], int left, int mid, int right, int count[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], Pair temp[], int left, int right, int count[]) {
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

    Pair arr[n], temp[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    printf("Count of smaller elements after self:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}