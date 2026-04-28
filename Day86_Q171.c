#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n) {
            return (int)mid;
        }
        else if (mid * mid < n) {
            ans = (int)mid;   // store possible answer
            low = (int)mid + 1;
        }
        else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int result = integerSqrt(n);
    printf("%d\n", result);

    return 0;
}