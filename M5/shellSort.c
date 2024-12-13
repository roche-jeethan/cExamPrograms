#include<stdio.h>
void shellSort(int arr[], int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }
}
void prinaArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    shellSort(arr,n);
    printf("Array after sorting: ");
    prinaArray(arr,n);  
    return 0;
}