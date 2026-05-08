#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {

    // Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    printf("Merged Intervals:\n");

    // First interval
    int start = arr[0].start;
    int end = arr[0].end;

    for (int i = 1; i < n; i++) {

        // Overlapping interval
        if (arr[i].start <= end) {

            // Extend end if needed
            if (arr[i].end > end) {
                end = arr[i].end;
            }
        }
        else {

            // Print previous merged interval
            printf("[%d, %d]\n", start, end);

            // Move to next interval
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    // Print last interval
    printf("[%d, %d]\n", start, end);
}

int main() {

    Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}