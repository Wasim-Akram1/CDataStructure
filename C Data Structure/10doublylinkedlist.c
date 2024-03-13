#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *Next;
    struct Node *Prev;
};
void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("ELement: %d\n",ptr->data);
        ptr=ptr->Next;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->Next=second;
    head->Prev=NULL;
    second->data=11;
    second->Next=third;
    second->Prev=head;
    third->data=64;
    third->Next=fourth;
    third->Prev=second;
    fourth->data=66;
    fourth->Next=fifth;
    fourth->Prev=third;
    fifth->data=98;
    fifth->Next=NULL;
    fifth->Prev=fourth;
    linkedListTraversal(head);
    return 0;
}