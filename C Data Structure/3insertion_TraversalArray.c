#include<stdio.h>
//Function for traversal 
void Display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int Insertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int main(){
    int arr[100]={1, 2, 6, 27, 78};
    int size=5, element=9, index=3;
    Display(arr, size);
    Insertion(arr, size, element, 100, index);
    size+=1;
    Display(arr,size);
    return 0;
}