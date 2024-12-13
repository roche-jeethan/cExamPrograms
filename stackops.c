#define max 5
#include<stdio.h>
#include<stdlib.h>
/**
 * @file stackops.c
 * @brief This file contains operations for stack manipulation.
 *
 * This file includes functions to perform various stack operations.
 * 
 * Note: The correct library for boolean operations in C is <stdbool.h>.
 */
#include<stdbool.h>
int top = -1; int stack[max];
void push(int item){
    if(top==max){
        printf("Overflow\n");
    } else{
        stack[++top]=item;
    }
}
void pop(){
    if(top=-1){
        printf("Underflow\n");
    } else {
        int item = stack[top];
        printf("Deleted item: %d",item);
        top--;
    }
}
bool isempty(){
    if(top==-1){
        return true;
    } else {
    return false;
    }
}
bool isfull(){
    if(top=max){
        return true;
    } else{
        return false;
    }
}
void display(){
}
int main(){
    int ch, item;
    bool res;
    while(true){
        printf("Stack Operations:\n1. Push\n2. Pop\n3. isempty\n4. isfull\n5. Display\n6. Exit\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    push(item); break;
            case 2: pop(); break;
            case 3: res = isempty(); res==true ? printf("It is empty\n") : printf("Not empty"); 
                    break;
            case 4: res = isfull(); res==true ? printf("It is full\n") : printf("Not full"); 
                    break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid option\n");
        }
    }
}
