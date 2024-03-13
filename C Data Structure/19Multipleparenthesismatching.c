#include <stdio.h>
#include <stdlib.h>
struct stack {
    int size;
    int top;
    char *arr; 
};
int isEmpty(struct stack *ptr) {
    return (ptr->top == -1);
}
int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1);
}
void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow!\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}
char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int parenthesisMatch(char *exp) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100; 
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i]=='{' || exp[i]=='[') {
            push(s, exp[i]);
        } else if ((exp[i] == ')' && pop(s) != '(')||
                    (exp[i]=='}' && pop(s)!='{')||
                    (exp[i]==']' && pop(s)!='[')){
            free(s->arr);
            free(s);
            return 0;
        }
    }
    int result = isEmpty(s);
    free(s->arr);
    free(s);
    return result;
}
int main() {
    char *exp = "{1(2[3]4)5}";
    if (parenthesisMatch(exp)) {
        printf("The parenthesis is matching\n");
    } else {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}