#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->capacity = 100;
    obj->size = 0;
    obj->arr = (int*)malloc(sizeof(int) * obj->capacity);
    return obj;
}

void addNum(MedianFinder* obj, int num) {

    if(obj->size == obj->capacity){
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, obj->capacity * sizeof(int));
    }

    int i = obj->size - 1;

    while(i >= 0 && obj->arr[i] > num){
        obj->arr[i+1] = obj->arr[i];
        i--;
    }

    obj->arr[i+1] = num;
    obj->size++;
}

double findMedian(MedianFinder* obj) {

    int n = obj->size;

    if(n % 2 == 1)
        return obj->arr[n/2];

    return (obj->arr[n/2] + obj->arr[n/2 - 1]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->arr);
    free(obj);
}

int main() {

    MedianFinder* mf = medianFinderCreate();

    addNum(mf,1);
    addNum(mf,2);

    printf("Median: %.2f\n", findMedian(mf));

    addNum(mf,3);

    printf("Median: %.2f\n", findMedian(mf));

    medianFinderFree(mf);

    return 0;
}