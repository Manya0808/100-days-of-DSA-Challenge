#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char *tokens[], int n) {
    int stack[100];
    int top = -1;

    for(int i = 0; i < n; i++) {

        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            if(strcmp(tokens[i], "+") == 0)
                stack[++top] = a + b;

            else if(strcmp(tokens[i], "-") == 0)
                stack[++top] = a - b;

            else if(strcmp(tokens[i], "*") == 0)
                stack[++top] = a * b;

            else
                stack[++top] = a / b;
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}

int main() {
    int n;

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    char *tokens[100];
    char temp[20];

    printf("Enter tokens:\n");

    for(int i = 0; i < n; i++) {
        scanf("%s", temp);
        tokens[i] = (char*)malloc(strlen(temp)+1);
        strcpy(tokens[i], temp);
    }

    int result = evalRPN(tokens, n);

    printf("Result = %d\n", result);

    return 0;
}