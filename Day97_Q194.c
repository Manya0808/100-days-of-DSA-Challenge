#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int start[], int end[], int n) {

    // Sort start and end times
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n && j < n) {

        // Need a new room
        if (start[i] < end[j]) {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        // Reuse a room
        else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {

    int start[] = {2, 9, 6};
    int end[] = {4, 12, 10};

    int n = sizeof(start) / sizeof(start[0]);

    int result = minMeetingRooms(start, end, n);

    printf("Minimum meeting rooms required = %d\n", result);

    return 0;
}