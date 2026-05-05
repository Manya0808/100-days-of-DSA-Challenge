#include <stdio.h>
#include <stdlib.h>

// Structure for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order (Insertion Sort inside bucket)
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;

    // Find position
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {
    // Create n buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(buckets);
}

// Main Function
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}