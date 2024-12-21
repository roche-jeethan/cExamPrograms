//Circular Queue with DMA using malloc
#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue{
    int *array;
    int front, rear, size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int capacity){
    CircularQueue *queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(CircularQueue *queue){
    return queue->size == queue->capacity;
}

int isEmpty(CircularQueue *queue){
    return queue->size == 0;
}

void enqueue(CircularQueue *queue, int item){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(CircularQueue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void display(CircularQueue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    for(int j = 0; j < queue->size; j++){
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main(){
    int capacity, choice, value;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);
    CircularQueue *queue = createQueue(capacity);
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                printf("Dequeued element is %d\n", dequeue(queue));
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

