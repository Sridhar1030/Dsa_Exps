#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top < MAX_SIZE - 1) {
        top++;
        stack[top] = value;
        
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop() {
    if (top >= 0) {
        
        return stack[top--];
    }
    printf("Stack underflow\n");
    exit(1);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char currentChar = infix[i];
        
        if (currentChar >= '0' && currentChar <= '9') {
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            push(currentChar);
        } else if (currentChar == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top >= 0 && stack[top] == '(') {
                pop(); // Pop '('
            }
        } else if (isOperator(currentChar)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar);
        }
        
        i++;
    }

    while (top >= 0) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
