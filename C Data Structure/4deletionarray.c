#include<stdio.h>
void Display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Deletion(int arr[], int size, int index){
    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
}
int main(){
    int arr[100]={7,8,12,27,78};
    int size=5, index=1;
    Display(arr,size);
    Deletion(arr,size,index);
    size-=1;
    Display(arr,size);
    return 0;
}