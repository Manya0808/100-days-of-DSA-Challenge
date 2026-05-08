#include <stdio.h>
#include <stdlib.h>

// Structure for meeting interval
typedef struct {
    int start;
    int end;
} Meeting;

// Compare meetings by start time
int compareMeetings(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

// ---------- Min Heap Functions ----------

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify upward
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

// Heapify downward
void heapifyDown(int heap[], int size, int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

// Insert into min heap
void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

// Remove minimum element
void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);
}

// Get minimum element
int getMin(int heap[]) {
    return heap[0];
}

// ---------- Main Function ----------

int minMeetingRooms(Meeting meetings[], int n) {

    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    // Min heap for end times
    int heap[n];
    int heapSize = 0;

    // First meeting
    insertHeap(heap, &heapSize, meetings[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {

        // If room becomes free
        if (meetings[i].start >= getMin(heap)) {
            removeMin(heap, &heapSize);
        }

        // Allocate current meeting
        insertHeap(heap, &heapSize, meetings[i].end);

        // Update maximum rooms used
        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {

    Meeting meetings[] = {
        {2, 4},
        {9, 12},
        {6, 10}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    int rooms = minMeetingRooms(meetings, n);

    printf("Minimum meeting rooms required = %d\n", rooms);

    return 0;
}