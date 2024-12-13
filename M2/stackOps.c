// stack operations
#define max 5
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int top = -1;
int stack[max];

void push(int item) {
    if (top == max - 1) {
        printf("Overflow\n");
    } else {
        stack[++top] = item;
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        int item = stack[top];
        printf("Deleted item: %d\n", item);
        top--;
    }
}

bool isempty() {
    return top == -1;
}

bool isfull() {
    return top == max - 1;
}

void display() {
    if (isempty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch, item;
    bool res;
    while (true) {
        printf("Stack Operations:\n1. Push\n2. Pop\n3. isempty\n4. isfull\n5. Display\n6. Exit\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                res = isempty();
                res ? printf("It is empty\n") : printf("Not empty\n");
                break;
            case 4:
                res = isfull();
                res ? printf("It is full\n") : printf("Not full\n");
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
}
