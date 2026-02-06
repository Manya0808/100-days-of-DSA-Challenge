/* Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <stdio.h>
int main(){
    
    int i, n, j = 0;
    int nums[50];
    printf("Enter the size of array = ");
    scanf("%d", &n);
    
    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    
    for(i = 0; i < n; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }

       while(j < n){
        nums[j] = 0;
        j++;
    }

    for(i = 0; i < n; i++){
        printf("%d ", nums[i]);
    }

    return 0;
}