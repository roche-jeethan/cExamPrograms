// addition of polynomials with linked list

#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
}; typedef struct node *NODE;

NODE head = NULL;

NODE create(int coeff, int exp){
    NODE snode = (NODE)malloc(sizeof(struct node));
    if(snode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    snode->coeff = coeff;
    snode->exp = exp;
    snode->next = NULL;
    return snode;
}

NODE insertend(NODE head, int coeff, int exp){
    NODE temp = create(coeff, exp);
    if(head==NULL){
        return temp;
    }
    NODE cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = temp;
    return head;
}
void display(NODE head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    while(cur != NULL){
        printf("%dx^%d ", cur->coeff, cur->exp);
        if(cur->next != NULL){
            printf("+ ");
        }
        cur = cur->next;
    }
    printf("\n");
}
NODE add(NODE poly1, NODE poly2){
    NODE res = NULL;
    NODE cur1 = poly1;
    NODE cur2 = poly2;
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->exp > cur2->exp){
            res = insertend(res, cur1->coeff, cur1->exp);
            cur1 = cur1->next;
        } else if(cur1->exp < cur2->exp){
            res = insertend(res, cur2->coeff, cur2->exp);
            cur2 = cur2->next;
        } else {
            res = insertend(res, cur1->coeff + cur2->coeff, cur1->exp);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    while(cur1 != NULL){
        res = insertend(res, cur1->coeff, cur1->exp);
        cur1 = cur1->next;
    }
    while(cur2 != NULL){
        res = insertend(res, cur2->coeff, cur2->exp);
        cur2 = cur2->next;
    }
    return res;
}
int main(){
    NODE poly1 = NULL;
    NODE poly2 = NULL;
    NODE res = NULL;
    poly1 = insertend(poly1, 5, 2);
    poly1 = insertend(poly1, 4, 1);
    poly1 = insertend(poly1, 2, 0);
    poly2 = insertend(poly2, 5, 1);
    poly2 = insertend(poly2, 5, 0);
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    res = add(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(res);
}