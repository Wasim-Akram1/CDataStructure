#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node * top=NULL;
void linkedlistTraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element:- %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int isEmpty(struct node*top){
    if(top==NULL){
        return 1;
    }
}
int isFull(struct node* top){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node* push(struct node * top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct node* tp){
    if(isEmpty(tp)){
        printf("stack Underflow\n");
    }
    else{
        struct node* n=tp;
        top=(tp)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    struct node * top=NULL;
    top=push(top,78);
    top=push(top,7);
    top=push(top,7);
    linkedlistTraversal(top);
    int element=pop(top);
    printf("popped element is %d",element);
    linkedlistTraversal(top);
    return 0;
}