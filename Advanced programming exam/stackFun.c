//
// Created by Huawei on 13/10/2022.
//

#include "stackFun.h"



stack *freeStack(stack *pStack) {
    node* p, *q;    //help pointer
    p=pStack->head;
    for (int i = 0; i < pStack->actualSize; ++i) {    //release each node of list
        q=p->next;
        free(p);
        p=q;
    }
    free(pStack);   //release pointer
    pStack=NULL;
    return pStack;
}

int pop(stack *pStack) {
    int r=0;
    if(pStack->actualSize==0)
        printf("pop with empty stack\n");  //check if already empty
    else{
        node *p;     //help pointer
        r=pStack->head->value;        //take first element
        p= pStack->head;
        pStack->head=pStack->head->next;    //change head
        free(p);              //release memory
        pStack->actualSize--;      //upgrade size
    }
    return r;   //release deleted element
}

void push(stack *pStack, valType el) {
    node* new;             //create new node
    new=(node*) malloc(sizeof(node));
    if (new==NULL){
        printf("impossible add element");
        exit(1);
    }else{
        new->value=el;    //insert value
        new->next=NULL;
        if (pStack->actualSize==0) pStack->head=new;    //if empty list insert in head
        else{
            new->next=pStack->head;    //else upgrade pointer and insert in head
            pStack->head=new;
        }
        pStack->actualSize++;   //upgrade size
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
            printf("\t%d", p->value);                        //CHANGE HERE IF CHANGE TYPE
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
    else{                        //create the struct of stack
        p->actualSize=0;
        p->head=NULL;
    }
    return p;
}
