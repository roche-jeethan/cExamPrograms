#include<stdio.h>
#include<stdlib.h>
#define max 5

void array2d();
void readsparse(int [][3]);
void transpose(int [][3],int [][3]);
void printsparse(int [][3]);

int main(){
    int a[max][3], b[max][3], m, n;
    printf("DMA of 2d array:\n\n");
    array2d();
    printf("Fast Transpose: \n\n");
    printf("Enter the number of rows and columns in the matrix (m,n): ");
    scanf("%d %d",&m,&n);
    a[0][0] = m;
    a[0][1] = n;
    readsparse(a);
    printf("Tranpose Process:\n");
    transpose(a,b);
    printsparse(b);
}
void array2d(){
    int i,j,**ptr,r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&r,&c);
    ptr = (int**)malloc(r*sizeof(int *));
    for(i=0;i<r;i++){
        ptr[i] = (int*)malloc(c*sizeof(int));
    }
    printf("Enter the array elements: ");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&ptr[i][j]);
        }
    }
    printf("Array elements are: ");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",ptr[i][j]);
        }
        printf("\n");
    }
}
void readsparse(int a[max][3]){
    int i,t;
    printf("Enter the number of non-zero elements: ");
    scanf("%d",&t);
    a[0][2] = t;
    for(i=1;i<=t;i++){
        printf("Enter the next triple (row,column,value): ");
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
}
void transpose(int a[max][3], int b[max][3]){
    int i,j,k,n;
    int rowterms[max], startingpos[max];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    k = a[0][1];
    n = a[0][2];
    for(i=0;i<k;i++){
        rowterms[i]=0;
    }
    for(i=1;i<=n;i++){
        rowterms[a[i][1]]++;
    }
    startingpos[0] = 1;
    for(i=1;i<k;i++){
        startingpos[i] = startingpos[i-1] + rowterms[i-1];
    }
    for(i=1;i<=n;i++){
        j = startingpos[a[i][1]]++;
        b[j][0] = a[i][1];
        b[j][1] = a[i][0];
        b[j][2] = a[i][2];
    }
}
void printsparse(int b[max][3]){
    int i,n;
    n = b[0][2];
    printf("\nAfter Transpose: ");
    printf("\nRow\t\tColumn\t\tValue\n");
    for(i=0;i<=n;i++){
        printf("%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2]);
    }
}