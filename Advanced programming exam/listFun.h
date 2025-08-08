//
// Created by Huawei on 16/09/2022.
//

#ifndef EXAM5_1_OTHER_H
#define EXAM5_1_OTHER_H

#include "stdio.h"
#include "stdlib.h"

//libraries of general functions with list of various type of element (change in the definition)
//double link list

typedef int valType;        //CHANGE TYPE HERE

typedef struct node{       //node struct
    valType val;              //value
    struct node *next;   //next el
    struct node *prev;   //pointer to previous element
}node;

void creatList(struct node **pHead);                //create the head of the list with flag value

void headInsert(valType el, struct node **pHead);    //insert element in head position(la testa è un nodo vedi se cambiarlo togliendo questa funzione e facendo direttamente gli insert)

void printList(struct node **pHead);             //print list from head to tail

void tailInsert(struct node **pHead, valType el);   //insert element in tail position

void indexInsert(struct node **pHead, int ind, valType el);   //insert in det index

void indexDelete(struct node **pHead, int ind);   //delete det index

int listLength(struct node **pHead);  //check length of the list

void indexRead(struct node **pHead, int ind);   //read value in det index

void printListBack(struct node **pHead);   //print list from tail to head

void checkEmpty(struct node **pHead);    //check if empty list

void delEl(struct node **pHead);    //ask index delete

void clearList(struct node **pHead);   //make list empty

void destroyList(struct node **pHead);   //delete also the header



#endif //EXAM5_1_OTHER_H
