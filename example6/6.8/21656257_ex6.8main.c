#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;        //val of the node
    struct node* next;   //pointer to next element
}node;

typedef struct queue{
    struct node* head;    //pointer to head and tail node
    struct node* tail;
}queue;

struct queue *initQueue(struct queue *pQueue);

void printQueue(struct queue *pQueue);

void enqueue(struct queue *pQueue, int el);

int dequeue(struct queue *pQueue);

int peekQueue(struct queue *pQueue);

void clearQueue(struct queue *pQueue);

int main() {
    struct queue *q;
    int a[6]={11, 22,33,44,55,66};
    q=initQueue(q);
    for (int i = 0; i < 6; ++i) {
        enqueue(q, a[i]);
    }
    printf("deQ = %d\n", dequeue(q));
    printf("-----------\n");
    printf("head = %d\n", peekQueue(q));
    printf("-----------\n");

    printQueue(q);
    clearQueue(q);
    free(q);
    return 0;
}

void clearQueue(struct queue *pQueue) {
    node* p=pQueue->head;
    while (p!=NULL){
        pQueue->head=pQueue->head->next;
        free(p);
        p=pQueue->head;
    }
    pQueue->tail=NULL;
}

int peekQueue(struct queue *pQueue) {
    int r=0;
    if (pQueue->head==NULL) printf("the queue is empty\n");
    else r=pQueue->head->data;
    return r;
}

int dequeue(struct queue *pQueue) {
    node *p;
    int r=0;
    if(pQueue->head==NULL) printf("the queue is empty\n");
    r=pQueue->head->data;
    p=pQueue->head;
    pQueue->head=p->next;
    if (pQueue->head==NULL) pQueue->tail=NULL;
    free(p);
    return r;
}

void enqueue(struct queue *pQueue, int el) {
    node *new;
    new=(node*) malloc(sizeof(node));
    if (new==NULL){
        printf("impossible add element\n");
        exit(1);
    } else{
        new->data=el;
        new->next=NULL;
        if (pQueue->tail==NULL)
            pQueue->head=pQueue->tail=new;
        else{
            pQueue->tail->next=new;
            pQueue->tail=pQueue->tail->next;
        }
    }
}

void printQueue(struct queue *pQueue) {
    node *p=pQueue->head;
    printf("The queue contains:\n");
    while (p!=NULL){
        printf("\t%d", p->data);
        p=p->next;
    }
}

struct queue *initQueue(struct queue *pQueue) {
    pQueue=(queue*) malloc(sizeof(queue));
    if (pQueue==NULL){
        printf("impossible create the queue\n");
        exit(1);
    } else{
        pQueue->tail=pQueue->head=NULL;
    }
    return pQueue;
}
