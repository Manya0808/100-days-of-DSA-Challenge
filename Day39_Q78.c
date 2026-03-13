#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    int freq;
};

int cmp(const void *a, const void *b) {
    struct Node *x = (struct Node *)a;
    struct Node *y = (struct Node *)b;
    return y->freq - x->freq;
}

int main() {
    int n, k;

    scanf("%d", &n);
    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    struct Node arr[n];
    int size = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < size; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(struct Node), cmp);

    for(int i = 0; i < k; i++) {
        printf("%d ", arr[i].num);
    }

    return 0;
}