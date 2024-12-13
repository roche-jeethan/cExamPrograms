//circular queue operations

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
char CQ[SIZE];
int f = 0, r = 0, count=0;/* Global declarations */
void CQinsert() {
    char elem;
    r = (r + 1) % SIZE;
    if (f==r) {
        printf("Queue Overflow!!!!\n");
        if(r==0)
            r=SIZE-1;
        else
            r=r-1;
    }
    else {
        printf("Enter the element to be Inserted \n");
        scanf(" %c", &CQ[r]); // Leave one extra space before %c count++;
    }
}
void CQdelete() {
    char elem;
    if (f==r) {
        printf("Queue Underflow!!!!\n");
    }
    else {
        f = (f + 1) % SIZE;
        count--;
        printf("The deleted Element is %c\n", CQ[f]);
    }
}
void CQdisplay() {
    int i,j;
    if (f==r)
        printf("Empty Queue\n");
    else {
        i=(f+1)%SIZE;
        for(j=1;j<=count;j++) {
            printf("%c\t",CQ[i]);
            i=(i+1)%SIZE;
        }
        printf("\n");
    }
}
int main(){
    int opn;
    char item;
    do {
        printf("1-Insert, 2-Delete,3-Display,4-Exit\n");
        printf("Enter Your option:");
        scanf("%d", &opn);
        switch (opn) {
            case 1:CQinsert();break;
            case 2:CQdelete();break;
            case 3:CQdisplay();break;
            case 4:printf("Terminating...\n");exit(0);
            default:printf("Invalid Option !!! Try Again !! \n"); break;
        }
        printf("Press a Key to Continue . . . \n");
    } while (opn != 4);
    return 0;
}