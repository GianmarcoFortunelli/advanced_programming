//
// Created by Huawei on 17/09/2022.
//

#ifndef EX5_3_OTHER_H
#define EX5_3_OTHER_H

#include "stdlib.h"
#include "stdio.h"

typedef struct node{
    int val;
    struct node *next;   //next el
}node, head;

void creatList(struct node **pHead);

void checkEmpty(struct node **pHead);

int listLength(struct node **pHead);

void printList(struct node **pHead);

void clearList(struct node **pHead);

void destroyList(struct node **pHead);

void indexRead(struct node **pHead, int ind);

void indexInsert(struct node **pHead, int ind, int el);

void indexDelete(struct node **pHead, int ind);




#endif //EX5_3_OTHER_H
