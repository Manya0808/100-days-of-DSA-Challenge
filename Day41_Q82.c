#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;

    for (int i = 0; i < 26; i++)
        if (freq[i] > maxFreq)
            maxFreq = freq[i];

    int maxCount = 0;

    for (int i = 0; i < 26; i++)
        if (freq[i] == maxFreq)
            maxCount++;

    int intervals = (maxFreq - 1) * (n + 1) + maxCount;

    return max(intervals, size);
}

int main() {
    int n, size;

    printf("Enter number of tasks: ");
    scanf("%d", &size);

    char tasks[size];

    printf("Enter tasks (A-Z): ");
    for (int i = 0; i < size; i++)
        scanf(" %c", &tasks[i]);

    printf("Enter cooling interval n: ");
    scanf("%d", &n);

    int result = leastInterval(tasks, size, n);

    printf("Minimum CPU intervals: %d\n", result);

    return 0;
}