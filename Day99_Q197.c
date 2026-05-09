#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

// Comparator for sorting in descending order of position
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Store position and time to reach target
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0;

    // Count fleets
    for (int i = 0; i < n; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};

    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, speed, n);

    printf("Number of Car Fleets = %d\n", result);

    return 0;
}