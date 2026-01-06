#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    top--;
}
char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
int isOperand(char c) {
    return isalnum(c);
}
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isOperand(c)) postfix[j++] = c; 
        else if (c == '(') push(c); 
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = peek();
                pop();
            }
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = peek();
                pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[j++] = peek();
        pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

//  output 
