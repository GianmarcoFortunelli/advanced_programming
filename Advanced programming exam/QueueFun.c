//
// Created by Huawei on 13/10/2022.
//

#include "QueueFun.h"


void clearQueue(struct queue *pQueue) {
    node* p=pQueue->head;
    while (p!=NULL){
        pQueue->head=pQueue->head->next;       //release memory of each node and set pointer to null
        free(p);
        p=pQueue->head;
    }
    pQueue->tail=NULL;
}

int peekQueue(struct queue *pQueue) {
    int r=0;
    if (pQueue->head==NULL) printf("the queue is empty\n");
    else r=pQueue->head->data;    //get value of next element
    return r;
}

int dequeue(struct queue *pQueue) {
    node *p;
    int r=0;
    if(pQueue->head==NULL) printf("the queue is empty\n");
    r=pQueue->head->data;
    p=pQueue->head;                      //remove first element upgrade pointer
    pQueue->head=p->next;
    if (pQueue->head==NULL) pQueue->tail=NULL;
    free(p);     //release memory
    return r;    //return his value
}

void enqueue(struct queue *pQueue, valType el) {
    node *new;
    new=(node*) malloc(sizeof(node));
    if (new==NULL){
        printf("impossible add element\n");
        exit(1);
    } else{                        //insert element
        new->data=el;
        new->next=NULL;
        if (pQueue->tail==NULL)                  //if first element  upgrade pointer
            pQueue->head=pQueue->tail=new;
        else{
            pQueue->tail->next=new;      //if not fist element upgrade pointer
            pQueue->tail=pQueue->tail->next;
        }
    }
}

void printQueue(struct queue *pQueue) {
    node *p=pQueue->head;
    printf("The queue contains:\n");
    while (p!=NULL){
        printf("\t%d", p->data);      //CHANGE HERE IF CHANGE TYPE
        p=p->next;
    }
}

struct queue *initQueue(struct queue *pQueue) {
    pQueue=(queue*) malloc(sizeof(queue));
    if (pQueue==NULL){
        printf("impossible create the queue\n");
        exit(1);
    } else{
        pQueue->tail=pQueue->head=NULL;     //create empty struct
    }
    return pQueue;
}


