#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 15
#define INF INT_MAX

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

// Recursive function
int solve(int mask, int pos) {
    // All cities visited → return to start (0)
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int city = 0; city < n; city++) {
        // If city not visited
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city);

            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int tsp() {
    memset(dp, -1, sizeof(dp));
    return solve(1, 0); // start from city 0
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("%d\n", tsp());

    return 0;
}