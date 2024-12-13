#include<stdio.h>
#include<stdlib.h>
int *ht; 
int key[20],m,n,i;
int count=0;
void insert(int key){
    int index = key % m;
    while(ht[index]!=-1){
        index = (index+1)%m;
    }
    ht[index]=key;
    count++;
}
void display(){
    int i;
    if(count==0){
        printf("Hash table is empty");
        return ;
    }
    printf("Hash table elements are: ");
    for(i=0;i<m;i++){
        printf("\nT[%d]->%d",i,ht[i]);
    }
}
int main(){
    int i;
    printf("Enter the number of employee: ");
    scanf("%d",&n);
    printf("Enter the two digit memory location: ");
    scanf("%d",&m);
    ht = (int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++){
        ht[i]=-1;
    }
    printf("Enter the 4 digit key of employees: ");
    for(i=0;i<n;i++){
        scanf("%d",&key[i]);
    }
    for(i=0;i<n;i++){
        if(count==m){
            printf("Hash table is full");
            break;
        }
        insert(key[i]);
    }
    display();
    return 0;
}