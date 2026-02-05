#include <stdio.h>

int main() {
    int p, q, log1[50], log2[50];
    int i, j;

    printf("Enter the number of entries in server log 1 = ");
    scanf("%d", &p);

    printf("Enter the elements of server 1: ");
    for(i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter the number of entries in server log 2 = ");
    scanf("%d", &q);

    printf("Enter the elements of server 2: ");
    for(i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    i = 0;
    j = 0;

    while(i < p && j < q) {
        if(log1[i] <= log2[j])
            printf("%d ", log1[i++]);
        else
            printf("%d ", log2[j++]);
    }

    while(i < p)
        printf("%d ", log1[i++]);

    while(j < q)
        printf("%d ", log2[j++]);

    return 0;
}
