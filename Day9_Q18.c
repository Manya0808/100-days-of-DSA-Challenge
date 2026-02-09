#include <stdio.h>

int main() {
    int n;
    char s[100005];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);   
    }

    int left = 0, right = n - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    for (int i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}
