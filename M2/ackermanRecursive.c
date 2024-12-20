//recursive ackermann function
#include<stdio.h>
int ackerman(int m, int n){
    if(m==0){
        return n+1;
    } else if(m>0 && n==0){
        return ackerman(m-1,1);
    } else if(m>0 && n>0){
        return ackerman(m-1,ackerman(m,n-1));
    }
}
int main(){
    int m,n;
    printf("Enter the parameters for the ackermann\'s function: ");
    scanf("%d %d",&m,&n);
    int res = ackerman(m,n);
    printf("The result is %d\n",res);
    return 0;
}