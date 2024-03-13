#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *Next;
};
void circularLinkedListTraversal(struct Node *head){
    struct Node *ptr=head;
    do{
        printf("element is %d \n",ptr->data);
        ptr=ptr->Next;
    }while(ptr!=head);
}
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->Next;
    while(p->Next!=head){
        p=p->Next;
    }
    p->Next=ptr;
    ptr->Next=head;
    head=ptr;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->Next=second;
    second->data=11;
    second->Next=third;
    third->data=64;
    third->Next=fourth;
    fourth->data=66;
    fourth->Next=head;
    printf("Before Insertion \n");
    circularLinkedListTraversal(head);
    head=insertAtFirst(head,88);
    printf("\nAfter Insertion \n");
    circularLinkedListTraversal(head);
    return 0;
}