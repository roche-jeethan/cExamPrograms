#define max 5
#include<stdio.h>
void addpoly(int poly1[], int poly2[], int result[], int degree){
    for(int i=0;i<=degree;i++){
        result[i] = poly1[i] + poly2[i];
    }
}
void printpoly(int poly[], int degree){
    for(int i=degree;i>=0;i--){
        if(poly[i]!=0){
            if(i==0){
                printf("%d",poly[i]);
            } else{
                printf("%dx^%d + ",poly[i],i);
            }
        }
    }
    printf("\n");
}
int main(){
    int poly1[max+1]={1,2,3,4};
    int poly2[max+1]={5,6,7,8};
    int result[max+1] = {0};
    addpoly(poly1,poly2,result,max);
    printf("Polynomial 1: ");
    printpoly(poly1,max);
    printf("Polynomial 2: ");
    printpoly(poly2,max);
    printf("Resultant Polynomial: ");
    printpoly(result,max);
    return 0;  
}