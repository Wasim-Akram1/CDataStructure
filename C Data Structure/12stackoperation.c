#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow cannot push %d to the stack \n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack UnderFlow! cannot pop the stack ");
        return -1;
    }
    else{
        int val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *s, int i){
    int arrInd=s->top-i+1;
    if(arrInd<0){
        printf("Not a valid position for stack \n");
        return -1;
    }
    else{
        return s->arr[arrInd];
    }
}
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    printf("the stack has been created.\n ");
    printf("Before Pushing, fuLl: %d\n",isFull(s));
    printf("Before pushing, Empty: %d\n",isEmpty(s));
    push(s,56);
    push(s,66);
    push(s,76);
    push(s,86);
    push(s,96);
    push(s,06);
    push(s,16);
    push(s,26);
    push(s,36);
    push(s,46);
    push(s,60);
    printf("After Pushing, Full:-%d \n", isFull(s));
    printf("After Pushing, Empty:-%d \n", isEmpty(s));
    printf("%d \n",isEmpty(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    for(int j=1; j<=s->top+1; j++){
        printf("the value at position %d is %d\n",j,peek(s,j));
    }
    return 0;
}