#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int k;
} KthLargest;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->arr = (int*)malloc(1000 * sizeof(int));
    obj->size = numsSize;
    obj->k = k;

    for(int i = 0; i < numsSize; i++)
        obj->arr[i] = nums[i];

    qsort(obj->arr, obj->size, sizeof(int), compare);

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    obj->arr[obj->size++] = val;

    qsort(obj->arr, obj->size, sizeof(int), compare);

    return obj->arr[obj->size - obj->k];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->arr);
    free(obj);
}

int main() {

    int nums[] = {4,5,8,2};
    int k = 3;

    KthLargest* obj = kthLargestCreate(k, nums, 4);

    printf("%d\n", kthLargestAdd(obj, 3));
    printf("%d\n", kthLargestAdd(obj, 5));
    printf("%d\n", kthLargestAdd(obj, 10));
    printf("%d\n", kthLargestAdd(obj, 9));
    printf("%d\n", kthLargestAdd(obj, 4));

    kthLargestFree(obj);

    return 0;
}

