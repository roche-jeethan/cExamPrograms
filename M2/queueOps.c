// Queue operations
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void insertQ() {
    int item;
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}
void deleteQ() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted element is %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}   
void search(int val){
    int i;
    for(i=front;i<=rear;i++){
        if(queue[i]==val){
            printf("Element found at index %d\n",i);
            return;
        }
    }
    printf("Element not found in the queue\n");
}
int main() {
    int ch, item, val;
    while (1) {
        printf("Queue Operations:\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertQ();
                break;
            case 2:
                deleteQ();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                printf("Terminating...\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}