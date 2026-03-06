#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    int stack[1000];
    int top = -1;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == strlen(s) - 1) {

            if (sign == '+')
                stack[++top] = num;

            else if (sign == '-')
                stack[++top] = -num;

            else if (sign == '*')
                stack[top] = stack[top] * num;

            else if (sign == '/')
                stack[top] = stack[top] / num;

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++)
        result += stack[i];

    return result;
}

int main() {
    char s[100];

    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    int result = calculate(s);

    printf("Result = %d\n", result);

    return 0;
}