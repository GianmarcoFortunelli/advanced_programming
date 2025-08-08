//
// Created by Huawei on 16/09/2022.
//

#ifndef EXAM5_1_OTHER_H
#define EXAM5_1_OTHER_H

#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int val;
    struct node *next;   //next el
    struct node *prev;   //pointer to previous element
}node;

void creatList(struct node **pHead);

void headInsert(int el, struct node **pHead);

void printList(struct node **pHead);

void tailInsert(struct node **pHead, int el);

void indexInsert(struct node **pHead, int ind, int el);

void indexDelete(struct node **pHead, int ind);

int listLength(struct node **pHead);

void indexRead(struct node **pHead, int ind);

void printMenu();

void printListBack(struct node **pHead);

void checkEmpty(struct node **pHead);

void delEl(struct node **pHead);

void insertEl(struct node **pHead);

void clearList(struct node **pHead);

void destroyList(struct node **pHead);



#endif //EXAM5_1_OTHER_H
