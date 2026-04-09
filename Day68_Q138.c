#include <stdio.h>
#include <string.h>

#define MAX 26

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void findOrder(char words[][100], int n) {
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // Mark characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len = strlen(w1) < strlen(w2) ? strlen(w1) : strlen(w2);
        int found = 0;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (adj[u][v] == 0) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case: "abc" before "ab"
        if (!found && strlen(w1) > strlen(w2)) {
            printf("Invalid Order\n");
            return;
        }
    }

    // Push nodes with indegree 0
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(i);
        }
    }

    char result[MAX];
    int idx = 0;

    // Topological Sort (BFS)
    while (!isEmpty()) {
        int node = dequeue();
        result[idx++] = node + 'a';

        for (int i = 0; i < MAX; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Count present characters
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) count++;
    }

    if (idx != count) {
        printf("Cycle exists → No valid order\n");
        return;
    }

    result[idx] = '\0';
    printf("Alien Order: %s\n", result);
}

// Driver code
int main() {
    char words[][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;

    findOrder(words, n);

    return 0;
}