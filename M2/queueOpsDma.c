//Queue operations with DMA
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int front, rear, size;
    int capacity;
    int *array;
}QUEUE;

QUEUE* createQueue(int capacity){
    QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(QUEUE *queue){
    return queue->size == queue->capacity;
}

int isEmpty(QUEUE *queue){
    return queue->size == 0;
}

void enqueue(QUEUE *queue, int item){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(QUEUE *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void display(QUEUE *queue){
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
    int ch, item;
    while(1){
        printf("1. Create Queue\n2. Enqueue\n3. Dequeue\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                int capacity;
                printf("Enter the capacity of the queue: ");
                scanf("%d", &capacity);
                QUEUE *queue = createQueue(capacity);
                break;
            case 2:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 3:
                item = dequeue(queue);
                if(item != -1){
                    printf("%d dequeued from queue\n", item);
                }
                break;
            case 4:
                display(queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
