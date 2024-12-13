#include<stdio.h>
#include<string.h>
void KMP(char *, char *);
void fail(char *,int,int *);
void printArray(int *, int);
int main(){
    char text[50],pattern[50];
    printf("Enter the text: ");
    scanf("%s",text);
    printf("Enter the pattern: ");
    scanf("%s",pattern);
    KMP(text,pattern);
    return 0;
}
void KMP(char *text, char *pattern){
    int i=0,j=0;
    int M = strlen(pattern); int N = strlen(text);
    int failure[M];
    fail(pattern,M,failure);
    while(i<N && j<M){
        if(text[i]==pattern[j]){
            i++; j++;
        } else if(j==0){
            i++;
        } else{
            j= failure[j-1]+1;
        }
    }
    if(j==M){
        printf("Pattern is found at %d\n",i-M);
    } else {
        printf("Pattern not found\n");
    }
}
void fail(char *pattern, int M, int *failure){
    int i,j;
    failure[0]= -1;
    for(j=1;j<M;j++){
        i = failure[j-1];
        while((pattern[j]!=pattern[i+1]) && i>=0){
            i = failure[i];
        } if(pattern[j]==pattern[i+1]){
            failure[j]=i+1;
        } else {
            failure[j] = -1;
        }
        printArray(failure,M);
    }
    
}
void printArray(int *arr,int n){
    int i; int count=1;
    for(i=0;i<n;i++){
        printf("Count [%d]: Failure function: \n",count);
        printf("%d\n",arr[i]);
        count++;
    }
    printf("\n\n");
}