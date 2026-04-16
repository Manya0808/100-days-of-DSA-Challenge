#include <stdio.h>

// Function to find longest zero sum subarray
int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;

    // Using array as hashmap (range assumption)
    int hash[10001];
    for (int i = 0; i < 10001; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = 5000; // to handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is zero
        if (sum == 0) {
            maxLength = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            if (i - prevIndex > maxLength)
                maxLength = i - prevIndex;
        } else {
            hash[sum + offset] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLen(arr, n);
    printf("%d\n", result);

    return 0;
}