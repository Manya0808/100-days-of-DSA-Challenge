/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

 Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

 Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 Return k.
*/

#include<stdio.h>
int main(){

    int n, nums[50], i, k;
    int value;

    printf("Enter size of array = ");
    scanf("%d", &n);
    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    printf("Enter value to remove: ");
    scanf("%d", &value);

    k = 0;
    for(i = 0; i < n; i++){
        if(nums[i] != value){
            nums[k] = nums[i];
            k++;
        }
    }

    printf("Array after removing element= ");
    for(i = 0; i < k; i++){
        printf("%d ", nums[i]);
    }

    return 0;
}