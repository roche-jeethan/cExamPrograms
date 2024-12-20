// stack operations using DMA
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *array;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(Stack *stack){
    return stack->top == stack->capacity - 1;
}
int isEmpty(Stack *stack){
    return stack->top == -1;
}
void push(Stack *stack, int item){
    if(isFull(stack)){
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
void pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    printf("%d popped from stack\n", stack->array[stack->top--]);
}
void display(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return;
    }
    for(int i = stack->top; i >= 0; i--){
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}
int main(){
    int capacity, choice, value;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);
    Stack *stack = createStack(capacity);
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}