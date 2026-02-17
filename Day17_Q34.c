#include <stdio.h>

int maxSubArray(int arr[], int n) {
    int currentSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < n; i++) {
        if(currentSum + arr[i] > arr[i])
            currentSum = currentSum + arr[i];
        else
            currentSum = arr[i];

        if(currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubArray(arr, n);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}
