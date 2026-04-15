#include <stdio.h>
#include <string.h>

#define MAX 100

int dp[MAX][MAX][MAX];
int boxes[MAX];

int solve(int l, int r, int k) {
    if (l > r) return 0;

    if (dp[l][r][k] != -1)
        return dp[l][r][k];

    int res = solve(l, r - 1, 0) + (k + 1) * (k + 1);

    for (int i = l; i < r; i++) {
        if (boxes[i] == boxes[r]) {
            int temp = solve(l, i, k + 1) + solve(i + 1, r - 1, 0);
            if (temp > res)
                res = temp;
        }
    }

    return dp[l][r][k] = res;
}

int removeBoxes(int arr[], int n) {
    memcpy(boxes, arr, sizeof(int) * n);
    memset(dp, -1, sizeof(dp));
    return solve(0, n - 1, 0);
}

int main() {
    int boxes1[] = {1,3,2,2,2,3,4,3,1};
    int n1 = sizeof(boxes1) / sizeof(boxes1[0]);
    printf("Output: %d\n", removeBoxes(boxes1, n1)); // 23

    int boxes2[] = {1,1,1};
    int n2 = sizeof(boxes2) / sizeof(boxes2[0]);
    printf("Output: %d\n", removeBoxes(boxes2, n2)); // 9

    int boxes3[] = {1};
    int n3 = sizeof(boxes3) / sizeof(boxes3[0]);
    printf("Output: %d\n", removeBoxes(boxes3, n3)); // 1

    return 0;
}