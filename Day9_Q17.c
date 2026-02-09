#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    int i, n;
    char temp;

    scanf("%s", s);

    n = strlen(s);
    for (i = 0; i < n / 2; i++) {
        temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    printf("%s", s);

    return 0;
}
