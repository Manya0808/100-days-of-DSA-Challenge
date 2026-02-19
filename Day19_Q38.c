#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = nums[0];
    
    int currentMax = nums[0];
    int maxSum = nums[0];
    
    int currentMin = nums[0];
    int minSum = nums[0];
    
    for(int i = 1; i < numsSize; i++){
        
        
        if(currentMax + nums[i] > nums[i])
            currentMax = currentMax + nums[i];
        else
            currentMax = nums[i];

        if(currentMax > maxSum)
            maxSum = currentMax;
        if(currentMin + nums[i] < nums[i])
            currentMin = currentMin + nums[i];
        else
            currentMin = nums[i];   

        if(currentMin < minSum)
            minSum = currentMin;
        
        totalSum += nums[i];
    }
    
    
    if(maxSum < 0)
        return maxSum;

 
    if(totalSum - minSum > maxSum)
        return totalSum - minSum;
    else
        return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", maxSubarraySumCircular(arr, n));

    return 0;
}
