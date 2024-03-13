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
struct Node *deleteFirst(struct Node *head){
    struct Node *ptr=head;
    head=head->Next;
    free(ptr);
    return head;
}
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p=head;
    struct Node *q=head->Next;
    for(int i=0; i<index-1; i++){
        p=p->Next;
        q=q->Next;
    }
    p->Next=q->Next;
    free(q);
    return head;
}
struct Node *deleteAtLast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->Next;
    while(q->Next!=NULL){
        p=p->Next;
        q=q->Next;
    }
    p->Next=q->Next;
    free(q);
    return head;
}
struct Node *deleteAtValue(struct Node *head, int value){
    struct Node *p=head;
    struct Node *q=head->Next;
    while(q->data!=value && q->Next!=NULL){
        p=p->Next;
        q=q->Next;
    }
    if(q->data==value){
        p->Next=q->Next;
    free(q);
    }
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
    head->data=4;
    head->Next=second;
    second->data=3;
    second->Next=third;
    third->data=8;
    third->Next=fourth;
    fourth->data=1;
    fourth->Next=NULL;
    printf("Before Deletion \n");
    linkedListTraversal(head);
    //head=deleteFirst(head);
    //head=deleteAtIndex(head,2);
    //head=deleteAtLast(head);
    head=deleteAtValue(head,1);
    printf("After Deletion \n");
    linkedListTraversal(head);
    return 0;
}