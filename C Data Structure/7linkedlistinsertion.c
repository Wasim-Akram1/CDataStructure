#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *Next;
};
void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("ELement: %d\n",ptr->data);
        ptr=ptr->Next;
    }
}
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node *ptr=malloc(sizeof(struct Node));
    ptr->Next=head;
    ptr->data=data;
    return ptr;
}
struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p==p->Next;
        i++;
    }
    ptr->data=data;
    ptr->Next=p->Next;
    p->Next=ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head;
    while(p->Next!=NULL){
       p=p->Next;
    }
    p->Next=ptr;
    ptr->Next=NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head, struct Node *preNode, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->Next=preNode->Next;
    preNode->Next=ptr;
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
    fourth->Next=NULL;
    printf("Before Insertion \n");
    linkedListTraversal(head);
    //head=(insertAtFirst(head,55));
    //head=insertAtIndex(head,56,1);
    //head=insertAtEnd(head,68);
    head=insertAfterNode(head,second,44);
    printf("\n AfterInsertion \n");
    linkedListTraversal(head);
    return 0;
}