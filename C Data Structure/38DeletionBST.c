#include<stdio.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
} 
void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct Node* inorderPredecessor(struct Node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node *deleteNode(struct Node* root, int val){
    struct Node* ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }
    else{
        ipre==inorderPredecessor(root);
        root->data=ipre->data;
        root->left=deleteNode(root->left,ipre->data);
    }
    return root;
}
int main(){
    struct Node* p=createNode(5);
    struct Node* p1=createNode(3);
    struct Node* p2=createNode(6);
    struct Node* p3=createNode(1);
    struct Node* p4=createNode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inOrder(p);
    printf("\n");
    deleteNode(p,5);
    inOrder(p);
    return 0;
}