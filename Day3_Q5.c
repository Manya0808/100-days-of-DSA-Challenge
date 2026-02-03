/* Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3
*/

#include<stdio.h>
int main(){
    
    int i, key, comparison = 0, n;
    int arr[50];

    printf("Enter the size of array = ");
    scanf("%d", &n);
    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of key = ");
    scanf("%d", &key);

    for(i = 0; i < n; i++){
        comparison++;
        if(arr[i] == key){
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", comparison);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", comparison);

    return 0;
}
