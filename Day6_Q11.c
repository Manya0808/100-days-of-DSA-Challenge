
/* Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3
*/

#include<stdio.h>
int main(){

    int i, n;
    int arr[50];
    printf("Enter the size of array = ");
    scanf("%d", &n);
    
    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d ", arr[0]);
    for(i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){
            printf("%d ", arr[i]);
        }
    }

    return 0;
}