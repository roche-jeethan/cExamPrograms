#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}; 
typedef struct node *NODE;
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
    temp -> next = head;
    head = temp;
    return temp;
}
NODE insertend(){
    NODE temp = create();
    if(temp==NULL){
        return head;
    }
    if(head == NULL){
        head = temp;
        return head;
    } else {
        NODE cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
    return head;
}
NODE insertAtPos(int pos){
    NODE temp = create();
    if(temp==NULL){
        return head;
    }
    NODE cur = head;
    for(int i=1; i<pos-1 && cur!=NULL; i++){
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
    NODE temp = head;
    head = head->next;
    free(temp);
    return head;
}
NODE deleteend(){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    NODE cur = head;
    while(cur->next->next != NULL){
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
    return head;
}
NODE deleteAtPos(int pos){
    NODE cur = head;
    for(int i=1; i<pos-1 && cur!=NULL; i++){
        cur = cur->next;
    }
    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return head;
}
NODE search(int val){
    NODE cur = head;
    int pos = 1;
    while(cur != NULL){
        if(cur->data == val){
            printf("Element found at position %d\n", pos);
            return cur;
        }
        cur = cur->next;
        pos++;
    }
}
void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    while(cur != NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
int main(){
    int ch, pos, val;
    while(1){
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
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
                    search(val);
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}