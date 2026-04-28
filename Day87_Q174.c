long long calculateHours(int* piles, int pilesSize, int k) {
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        // ceil(piles[i] / k)
        hours += (piles[i] + k - 1) / k;
    }

    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;

    // find max pile
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = calculateHours(piles, pilesSize, mid);

        if (hours <= h) {
            ans = mid;          // possible answer
            high = mid - 1;     // try smaller k
        } else {
            low = mid + 1;      // need bigger k
        }
    }

    return ans;
}