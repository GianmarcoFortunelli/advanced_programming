//
// Created by Huawei on 13/10/2022.
//

#ifndef EX6_8_QUEUEFUN_H
#define EX6_8_QUEUEFUN_H

#include <stdio.h>
#include <stdlib.h>

//library of functions to use in Queue according to FIFO logic
//change type in fun below

//first raw of main struct queue *q;
//                  q=initQueue(q);

typedef int valType;

typedef struct node{
    valType data;        //val of the node
    struct node* next;   //pointer to next element
}node;

typedef struct queue{
    struct node* head;    //pointer to head and tail node
    struct node* tail;
}queue;

struct queue *initQueue(struct queue *pQueue);   //create the queue struct

void printQueue(struct queue *pQueue);       //print element from head to tail

void enqueue(struct queue *pQueue, valType el);    //insert element according LIFO

int dequeue(struct queue *pQueue);             //remove element according LIFO

int peekQueue(struct queue *pQueue);           //Get value of next el

void clearQueue(struct queue *pQueue);         //get queue empty


#endif //EX6_8_QUEUEFUN_H
