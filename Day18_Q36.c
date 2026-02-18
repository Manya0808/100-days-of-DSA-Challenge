#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
        result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= right;
        right *= nums[i];
    }

    return result;
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

    int* result = productExceptSelf(nums, n);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(result);  
    return 0;
}


