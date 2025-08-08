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

void enqueue(struct queue *pQueue, int el);

int dequeue(struct queue *pQueue);

int main() {
    struct queue *q;
    q=initQueue(q);  //list where the first 4 position are the counter
    int c=0, n=0, nEl=0; //choice variable, number of clients of the day and number of clients in the bank

    while (c!=-1) {
        printf("User Menu:\n"
               "\t1)Get number\n"
               "\t2)Next costumer\n"
               "\t-1)exit\n");
        scanf("%d", &c);
        switch (c) {                    //analyzing choice
            case 1:
                printf("your number is %d\n", ++n);
                enqueue(q,n);      //add client to queue
                nEl++;                          //new client in the bank
                if(nEl<=4)
                    printf("it's your turn\n");                               //if less than 4 one counter is free
                else printf("you have %d people ahead you\n", nEl-4);         //else you have someone ahead
                break;
            case 2:
                if(nEl==0)
                    printf("nobody in Queue\n");     //nobody in the back
                else if (nEl<5){
                    printf("nobody in Queue\n");             //less then 4 people remove one client but isn't the turn of somebody
                    dequeue(q);      //remove client and go to the next
                    nEl--;
                }
                else {                                                  //else remove one client and call the next
                    dequeue(q);      //remove client and go to the next
                    nEl--;
                    node *p = q->head;
                    for (int i = 0; i < 3; ++i) {
                        p = p->next;                //looking for next client
                    }
                    printf("%d is your turn\n", p->data);
                }
                break;
            case -1: printf("closing programm...\n"); break;          //print info
            default: printf("wrong choice\n");  break;
        }

    }
    return 0;
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
