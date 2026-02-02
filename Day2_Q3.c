#include<stdio.h>
int main(){

    int i, pos, n;
    int arr[50];

    printf("Enter the size of array = ");
    scanf("%d", &n);
    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the position element to be deleted = ");
    scanf("%d", &pos);

    for(i = pos - 1; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--;

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}