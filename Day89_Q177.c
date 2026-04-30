#include <stdio.h>

// Check if allocation is possible
int isPossible(int books[], int n, int m, int maxPages) {
    int studentCount = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → impossible
        if (books[i] > maxPages)
            return 0;

        if (currentPages + books[i] > maxPages) {
            studentCount++;
            currentPages = books[i];

            if (studentCount > m)
                return 0;
        } else {
            currentPages += books[i];
        }
    }

    return 1;
}

// Main function to find minimum maximum pages
int allocateBooks(int books[], int n, int m) {
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > left)
            left = books[i];   // max element
        right += books[i];     // total sum
    }

    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(books, n, m, mid)) {
            answer = mid;
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // increase limit
        }
    }

    return answer;
}

int main() {
    int n, m;

    // Input
    scanf("%d %d", &n, &m);

    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    // Edge case
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    // Output
    printf("%d\n", allocateBooks(books, n, m));

    return 0;
}