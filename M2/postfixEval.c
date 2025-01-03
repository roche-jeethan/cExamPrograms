#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return stack[top--];
    }
}

void postEval(char* exp) {
    char* token = strtok(exp, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (token[0]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': 
                    if (val1 != 0) {
                        push(val2 / val1); 
                    } else {
                        printf("Division by zero error\n");
                        return;
                    }
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", token[0]);
                    return;
            }
        }
        token = strtok(NULL, " ");
    }
    if (top == 0) {
        printf("Result of expression evaluation: %d\n", pop());
    } else {
        printf("Invalid postfix expression\n");
    }
}

int main() {
    char text[100];
    printf("Enter the Postfix Expression (space-separated): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    postEval(text);
    return 0;
}
