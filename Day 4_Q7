#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 0, right = n - 1;
    while(left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
