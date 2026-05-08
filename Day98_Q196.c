#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// Compare intervals by start time
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

void mergeIntervals(Interval arr[], int n) {

    // Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array for merged intervals
    Interval result[n];

    int index = 0;

    // First interval
    result[index] = arr[0];

    for (int i = 1; i < n; i++) {

        // Overlapping intervals
        if (arr[i].start <= result[index].end) {

            // Update end if needed
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        }
        else {
            // Add new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
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