#include <stdio.h>
#include <stdlib.h>


typedef struct dynStack {
    int maxSize;    //physical size
    int top;        //index of operation
    int* dArray;    //array pointer
}stack;

void push(stack *stack,int el);
int empty(stack *stack);
int pop(stack *stack);

stack *creatStack(int size);

void printStack(stack *pStack);

void freeStack(stack *pStack);

int main() {
    stack *s;
    s=creatStack(6);   //create an array whit size 6
    push(s, 11);    //insert element
    push(s, 22);
    printStack(s);   //print all the stack
    printf("----------\n");
    push(s, 33);
    push(s, 44);
    printStack(s);
    printf("----------\n");
    printf("pop = %d\n", pop(s));    //delete element
    printStack(s);
    printf("----------\n");

    freeStack(s);   //release memory
    return 0;
}

void freeStack(stack *pStack) {
    free(pStack->dArray);
    free(pStack);
}

void printStack(stack *pStack) {
    printf("The stack contains:\n");
    for (int i = pStack->top+1; i < pStack->maxSize;i++) {
        printf("\t%d", pStack->dArray[i]);
    }
    printf("\tend\n");
}

stack *creatStack(int size) {
    stack *s;
    s=(stack *) malloc(sizeof(stack));
    if (s==NULL){
        printf("impossible create array\n");
        exit(1);
    } else{
        s->dArray=(int *) malloc(size* sizeof(int));
        if (s->dArray==NULL){
            printf("impossible create array\n");
            exit(1);
        } else{
            s->maxSize=size;
            s->top=s->maxSize-1;
            for (int i = 0; i < s->maxSize; ++i) {
                s->dArray[i]=0;}
        }
    }
    return s;
}

int pop(stack *stack) {
    int r=0;
    if (stack->top==stack->maxSize-1){
        printf("pop with empty stack\n");
    } else{
        r=stack->dArray[stack->top+1];
        stack->dArray[stack->top+1]=0;
        stack->top++;
    }
    return r;
}

int empty(stack *stack){
    int r;                    //using a return variables to permit to design a correct flowchart
    if(stack->top==stack->maxSize-1) r=1;   //if index point to last position stack empty
    else r=0;
    return r;
}

void push(stack *stack, int el) {
    if (stack->top>=0){                 //if  not empty insert element
        stack->dArray[stack->top--]=el;     //also upgrade top index
    } else printf("the stack is full on push\n");
}
