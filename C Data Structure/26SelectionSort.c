#include<stdio.h>
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int selctionSort(int *A, int n){
    int indexofMin, temp;
    printf("Running selection sort\n");
    for(int i=0; i<n-1; i++){
        indexofMin=i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[indexofMin]){
                indexofMin=j;
            }
        }
        temp=A[i];
        A[i]=A[indexofMin];
        A[indexofMin]=temp;
    }
}
int main(){
    int n=5;
    int A[]={12,4,64,88,15};
    printArray(A,n);
    selctionSort(A,n);
    printArray(A,n);
    return 0;
}