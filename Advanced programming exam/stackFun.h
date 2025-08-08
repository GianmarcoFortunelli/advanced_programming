//
// Created by Huawei on 13/10/2022.
//

#ifndef INC_6_4_STACKFUN_H
#define INC_6_4_STACKFUN_H

#include <stdio.h>
#include <stdlib.h>

//library of basic functions of stack with list implementation   LIFO logic
//change type of info changing typedef

//main first raw  stack* s;
//                s=createStack()   //use s as pointer to stack struct

typedef int valType;

typedef struct node{
    valType value;         //value of node
    struct node* next;    //next node of list
}node;

typedef struct stack{
    int actualSize;     //size of list
    struct node* head;    //head pointer to list
}stack;

stack *createStack();                       //crate struct stack

void printStack(stack *pStack);          //print all the element in the list

void push(stack *pStack, valType el);    //insert element according to LIFO

int pop(stack *pStack);           //remove element according LIFO

stack *freeStack(stack *pStack);    //clean the stack


#endif //INC_6_4_STACKFUN_H
