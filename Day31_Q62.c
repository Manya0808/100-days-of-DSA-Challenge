#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[1000];  
    int top = -1;

    for(int i = 0; i < n; i++) {
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else {
            if(top == -1) return false;

            char topChar = stack[top--];

            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (top == -1);
}

int main() {
    char str[1000];

    printf("Enter brackets string: ");
    scanf("%s", str);

    if(isValid(str))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}