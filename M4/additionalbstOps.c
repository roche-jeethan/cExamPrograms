#include<stdio.h>
#include<stdlib.h>
treepointer copy(treepointer original){
    treepointer temp;
    if(original){
        temp = (treepointer)malloc(sizeof(struct *temp));
        temp->lchild = copy(original->lchild);
        temp->rchild = copy(original->rchild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}
int equal(treepointer first, treepointer second){
    return((!first && !second) || (first && second && first->data == second->data && equal(first->lchild, second->lchild) && equal(first->rchild, second->rchild)));
}