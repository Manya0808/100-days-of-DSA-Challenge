/*Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

#include<stdio.h>
int main(){
    int m, n, i, j, k;
    int nums1[100], nums2[50];
    printf("Enter number of elements in nums1= ");
    scanf("%d", &m);
    printf("Enter %d sorted elements of nums1= ", m);
    for(i = 0; i < m; i++){
        scanf("%d", &nums1[i]);
    }

    for(i = m; i < m + n; i++){
        nums1[i] = 0;
    }
    
    printf("Enter number of elements in nums2= ");
    scanf("%d", &n);
    printf("Enter %d sorted elements of nums2= ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &nums2[i]);
    }

    i = m - 1;
    j = n - 1;
    k = m + n - 1;

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    printf("Merged array= ");
    for (i = 0; i < m + n; i++){
        printf("%d ", nums1[i]);
    }

    return 0;
}