#include<stdio.h>
void prinaArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}   
void insertionSort(int arr[], int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[30],i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");   
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: ");
    prinaArray(arr,n);
    insertionSort(arr,n);
    printf("Array after sorting: ");
    prinaArray(arr,n);  
    return 0;
}