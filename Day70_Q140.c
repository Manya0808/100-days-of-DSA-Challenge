#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int city;
    int cost;
    int stops;
} Node;

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    
    int cost[n];
    for(int i = 0; i < n; i++)
        cost[i] = INT_MAX;

    cost[src] = 0;

    Node queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Node){src, 0, 0};

    while(front < rear) {
        Node curr = queue[front++];

        if(curr.stops > k) continue;

        for(int i = 0; i < flightsSize; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            if(u == curr.city) {
                if(curr.cost + price < cost[v]) {
                    cost[v] = curr.cost + price;
                    queue[rear++] = (Node){v, cost[v], curr.stops + 1};
                }
            }
        }
    }

    return (cost[dst] == INT_MAX) ? -1 : cost[dst];
}

int main() {
    int n = 3;
    int flights[][3] = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int flightsSize = 3;

    int src = 0, dst = 2, k = 1;

    int result = findCheapestPrice(n, flights, flightsSize, src, dst, k);

    printf("Cheapest Price: %d\n", result);

    return 0;
}