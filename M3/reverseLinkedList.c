#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};typedef struct Node *NODE;
NODE reverseList(NODE head) {
    NODE prev = NULL;
    NODE current = head;
    NODE next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;         
        current = next;
    }
    return prev;
}
void printList(NODE head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void append(NODE* head, int newData) {
    NODE temp = (NODE)malloc(sizeof(struct Node));
    NODE last = *head;
    temp->data = newData;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
}
int main() {
    NODE head = NULL;
    int n, value;
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }
    printf("Original List: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed List: ");
    printList(head);
    return 0;
}
