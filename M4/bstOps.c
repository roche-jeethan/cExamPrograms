/* the program is modular and hence it has all the functions present, 
but any functions of the choice needs to be chosen */

#include<stdio.h>
#include<stdlib.h>

struct BST{
    struct BST *lchild;
    int data;
    struct BST *rchild;
};
typedef struct BST *NODE;

NODE create(int val){
    NODE temp = (NODE)malloc(sizeof(struct BST));
    temp->data = val;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
void insert(NODE root, NODE newnode){
    if(newnode->data < root->data){
        if(root->lchild == NULL){
            root->lchild = newnode;
        } else{
            insert(root->lchild, newnode);
        }
    } else if(newnode->data > root->data){
        if(root->rchild == NULL){
            root->rchild = newnode;
        } else{
            insert(root->rchild, newnode);
        }
    }
}
void search(NODE root, int key){
    NODE cur = root;
    while(cur){
        if(cur->data == key){
            printf("Key Element found in BST\n");
            return;
        } else if(cur->data < key){
            cur = cur->lchild;
        } else{
            cur = cur->rchild;
        }
    }
    printf("Key Element not found in BST\n");
}
void inorder(NODE root){
    if(root){
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
void preorder(NODE root){
    if(root){
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(NODE root){
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}
NODE delete(NODE root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->lchild = delete(root->lchild, key);
    } else if(key > root->data){
        root->rchild = delete(root->rchild, key);
    } else{
        if(root->lchild == NULL){
            NODE temp = root->rchild;
            free(root);
            return temp;
        } else if(root->rchild == NULL){
            NODE temp = root->lchild;
            free(root);
            return temp;
        }
        NODE temp = root->rchild;
        while(temp->lchild){
            temp = temp->lchild;
        }
        root->data = temp->data;
        root->rchild = delete(root->rchild, temp->data);
    }
    return root;
}
int count(NODE root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->lchild) + count(root->rchild);
}
NODE smallest(NODE root){
    if(root==NULL || root->lchild==NULL){
        return root;
    } else {
        return smallest(root->lchild);
    }
}
NODE largest(NODE root){
    if(root==NULL || root->rchild==NULL){
        return root;
    } else {
        return largest(root->rchild);
    }
}
int height(NODE root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->lchild);
    int rh = height(root->rchild);
    if(lh > rh){
        return 1 + lh;
    } else{
        return 1 + rh;
    }
}
int main(){
    NODE root = NULL;
    int ch,n,val;
    while(1){
        printf("1. Create\n2. Insert\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Delete\n8. Count\n9. Smallest\n10. Largest\n11. Height\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("Enter the number of nodes: ");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("Enter value: ");
                    scanf("%d",&val);
                    NODE newnode = create(val);
                    if(root==NULL){
                        root = newnode;
                    } else {
                        insert(root, newnode);
                    }
                }
                break;
            }
            case 2: {
                printf("Enter the node value: ");
                int val;
                scanf("%d",&val);
                NODE newnode = create(val);
                insert(root, newnode);
                break;
            }
            case 3: {
                printf("Enter the key element to search: ");
                int key;
                scanf("%d",&key);
                search(root, key);
                break;
            }
            case 4: {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 5: {
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            }
            case 6: {
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            }
            case 7: {
                printf("Enter the key element to delete: ");
                int key;
                scanf("%d",&key);
                root = delete(root, key);
                break;
            }
            case 8: {
                printf("Number of nodes in BST: %d\n",count(root));
                break;
            }
            case 9: {
                NODE small = smallest(root);
                printf("Smallest element in BST: %d\n",small->data);
                break;
            }
            case 10: {
                NODE large = largest(root);
                printf("Largest element in BST: %d\n",large->data);
                break;
            }
            case 11: {
                printf("Height of BST: %d\n",height(root));
                break;
            }
            case 12: exit(0);
            default: printf("Invalid option\n");
        }
    }
}