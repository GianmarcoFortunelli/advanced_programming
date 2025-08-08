#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;         //value of node
    struct node* next;    //next node of list
}node;

typedef struct stack{
    int actualSize;     //size of list
    struct node* head;    //head pointer to list
}stack;

stack *createStack();

void printStack(stack *pStack);

void push(stack *pStack, int el);

int pop(stack *pStack);

stack *freeStack(stack *pStack);

int main() {
    stack* s;
    s=createStack();
    printStack(s);
    printf("----------\n");

    push(s,11);
    push(s,22);
    push(s,33);
    printStack(s);
    printf("----------\n");

    printf("pop = %d\n", pop(s));
    printf("pop = %d\n", pop(s));
    printStack(s);
    printf("----------\n");

    s=freeStack(s);
    printStack(s);
    printf("----------\n");
    return 0;
}

stack *freeStack(stack *pStack) {
    node* p, *q;    //help pointer
    p=pStack->head;
    for (int i = 0; i < pStack->actualSize; ++i) {
        q=p->next;
        free(p);
        p=q;
    }
    free(pStack);
    pStack=NULL;
    return pStack;
}

int pop(stack *pStack) {
    int r=0;
    if(pStack->actualSize==0)
        printf("pop with empty stack\n");
    else{
        node *p;     //help pointer
        r=pStack->head->value;
        p= pStack->head;
        pStack->head=pStack->head->next;
        free(p);
        pStack->actualSize--;
    }
    return r;
}

void push(stack *pStack, int el) {
    node* new;             //create new node
    new=(node*) malloc(sizeof(node));
    if (new==NULL){
        printf("impossible add element");
        exit(1);
    }else{
        new->value=el;    //insert value
        new->next=NULL;
        if (pStack->actualSize==0) pStack->head=new;
        else{
            new->next=pStack->head;
            pStack->head=new;
        }
        pStack->actualSize++;
    }
}

void printStack(stack *pStack) {
    if (pStack==NULL) printf("the stack doesn't exist\n");
    else if (pStack->head==NULL) printf("the stack is empty\n");
    else{
        node* p;
        p=pStack->head;
        printf("the stack contains:\n");
        for (int i = 0; i < pStack->actualSize; ++i) {
            printf("\t%d", p->value);
            p=p->next;
        }
        printf("\tend\n");
    }
}

stack *createStack() {
    stack* p;
    p=(stack*) malloc(sizeof(stack));
    if (p==NULL){
        printf("impossible create stack\n");
        exit(1);
    }
    else{
        p->actualSize=0;
        p->head=NULL;
    }
    return p;
}
