#include<stdio.h>
#include<stdlib.h>
struct Node *f=NULL;
struct Node *r=NULL;
struct Node{
    int data;
    struct Node *Next;
};
void linkedListTraversal(struct Node *ptr){
    printf("Printing the elements of this linked list\n");
    while(ptr!=NULL){
        printf("ELement: %d\n",ptr->data);
        ptr=ptr->Next;
    }
}
void enqueue(int val){
    struct Node *n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("The queue is full\n");
    }
    else{
        n->data=val;
        n->Next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->Next=n;
            r=n;
        }
    }
}
int dequeue(){
    int val=-1;
    struct Node *ptr=f;
    if(f==NULL){
        printf("The queue is empty\n");
    }
    else{
        f=f->Next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    linkedListTraversal(f);
    printf("Dequing element %d\n",dequeue());
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Dequing element %d\n",dequeue());
    printf("Dequing element %d\n",dequeue());
    printf("Dequing element %d\n",dequeue());
    linkedListTraversal(f);
    return 0;
    }