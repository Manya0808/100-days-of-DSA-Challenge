#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int nums[], int n, int k, int *returnSize) {
    int *result = (int*)malloc((n-k+1)*sizeof(int));
    int *dq = (int*)malloc(n*sizeof(int));

    int front = 0, rear = 0;
    *returnSize = 0;

    for(int i = 0; i < n; i++) {

        // Remove indices outside window
        if(front < rear && dq[front] <= i-k)
            front++;

        // Remove smaller elements
        while(front < rear && nums[dq[rear-1]] < nums[i])
            rear--;

        dq[rear++] = i;

        // Store maximum
        if(i >= k-1)
            result[(*returnSize)++] = nums[dq[front]];
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int nums[n];

    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    printf("Enter window size k: ");
    scanf("%d",&k);

    int returnSize;
    int *ans = maxSlidingWindow(nums,n,k,&returnSize);

    printf("Sliding window maximums:\n");
    for(int i=0;i<returnSize;i++)
        printf("%d ",ans[i]);

    return 0;
}