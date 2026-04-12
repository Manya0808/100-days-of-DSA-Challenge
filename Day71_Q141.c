#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];  // max size

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            break;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    
    scanf("%d", &m);  // table size
    scanf("%d", &q);  // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}