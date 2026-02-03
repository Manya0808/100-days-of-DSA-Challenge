/* You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
*/

#include<stdio.h>
int main(){

    int i, n;
    int arr[50];
    int exp_sum, sum = 0, missing;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter %d elements of the array:\n", n - 1);
    for(i = 0; i < n - 1; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    exp_sum = n * (n + 1) / 2;
    missing = exp_sum - sum;

    printf("Missing number is: %d\n", missing);

    return 0;
}
