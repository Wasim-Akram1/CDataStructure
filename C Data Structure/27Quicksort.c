#include<stdio.h>
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int partition(int A[], int low, int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if (i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void quickSort(int A[],int low, int high){
    int partitonIndex;
    if(low<high){
        partitonIndex=partition(A,low,high);
        quickSort(A, low, partitonIndex-1);
        quickSort(A, partitonIndex+1, high);
    }
}
int main(){
    int A[]={3,5,2,13,12,3,2,13,45};
    int n=9;
    printArray(A,n);
    quickSort(A, 0, n-1);
    printf("Aftr the quick sort\n");
    printArray(A, n);
    return 0;
}