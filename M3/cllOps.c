//Single Circular Linked List Operations

#include<stdio.h>
#include<stdlib.h> 
struct node{
    int data;
    struct node *next;
}; typedef struct node *NODE;

NODE head = NULL;

NODE create(){
    NODE snode = (NODE)malloc(sizeof(struct node));
    if(snode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data: ");
    scanf("%d", &snode->data);
    snode->next = NULL;
    return snode;
}

NODE insertbeg(){
    NODE temp = create();
    if(temp==NULL){
        return head;
    }
    if(head == NULL){
        head = temp;
        temp->next = head;
    } else {
        NODE cur = head;
        while(cur->next != head){
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
        head = temp;
    }
    return head;
}

NODE insertend(){
    NODE temp = create();
    if(temp==NULL){
        return head;
    }
    if(head == NULL){
        head = temp;
        temp->next = head;
    } else {
        NODE cur = head;
        while(cur->next != head){
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
    }
    return head;
}

NODE insertAtPos(int pos){
    NODE temp = create();
    if(temp==NULL){
        return head;
    }
    if(pos == 1){
        return insertbeg();
    }
    NODE cur = head;
    for(int i=1; i<pos-1 && cur->next != head; i++){
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    return head;
}   

NODE deletebeg(){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    NODE cur = head;
    while(cur->next != head){
        cur = cur->next;
    }
    cur->next = head->next;
    free(head);
    head = cur->next;
    return head;
}

NODE deleteend(){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    NODE cur = head;
    while(cur->next->next != head){
        cur = cur->next;
    }
    free(cur->next);
    cur->next = head;
    return head;
}

NODE deleteAtPos(int pos){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(pos == 1){
        return deletebeg();
    }
    NODE cur = head;
    for(int i=1; i<pos-1 && cur->next != head; i++){
        cur = cur->next;
    }
    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return head;
}

NODE search(int val){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    NODE cur = head;
    int pos = 1;
    while(cur->next != head){
        if(cur->data == val){
            printf("Element found at position %d\n", pos);
            return head;
        }
        cur = cur->next;
        pos++;
    }
    if(cur->data == val){
        printf("Element found at position %d\n", pos);
    } else {
        printf("Element not found\n");
    }
    return head;
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    do{
        printf("%d ", cur->data);
        cur = cur->next;
    } while(cur != head);
    printf("\n");
}

int main(){
    int ch, pos, val;
    while(1){
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Search\n8. Display\n9. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: head = insertbeg();
                    break;
            case 2: head = insertend();
                    break;
            case 3: printf("Enter the position: ");
                    scanf("%d", &pos);
                    head = insertAtPos(pos);
                    break;
            case 4: head = deletebeg();
                    break;
            case 5: head = deleteend();
                    break;
            case 6: printf("Enter the position: ");
                    scanf("%d", &pos);
                    head = deleteAtPos(pos);
                    break;
            case 7: printf("Enter the value to be searched: ");
                    scanf("%d", &val);
                    head = search(val);
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}