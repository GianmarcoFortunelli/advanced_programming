#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int maxSize;
    int head;
    int tail;
    int nEl;
    int *array;
}queue;


void enqueue(queue* pQueue, int el);
int empty(queue* pQueue);
int dequeue(queue* pQueue);

queue *createQueue(int size);

void freeQueue(queue *pQueue);

void printQueue(queue *pQueue);

int main() {
    queue* q;
    q=createQueue(3);
    enqueue(q,11);
    enqueue(q,22);
    enqueue(q,33);
    enqueue(q,44);
    printQueue(q);
    printf("---------\n");
    printf("deQ = %d\n", dequeue(q));
    printf("deQ = %d\n", dequeue(q));
    printf("---------\n");
    printQueue(q);
    printf("---------\n");
    freeQueue(q);
    return 0;
}

void printQueue(queue *pQueue) {
    printf("the queue contains:\n");;
    if (pQueue->head==pQueue->tail && pQueue->array[0]==0) printf("queue is empty\n");     //if the two pointer is the same, but one element is zero is empty, otherwise is full
    else if(pQueue->head<pQueue->tail){
        for (int i = pQueue->head; i < pQueue->tail; ++i) {             //if head and tail in the same "circle"
            printf("\t%d", pQueue->array[i]);
        }
        printf("\tend\n");
    } else{
        for (int i = pQueue->head; i < pQueue->maxSize; ++i) {     //else i have to restart from first element
            printf("\t%d", pQueue->array[i]);
        }for (int i = 0; i < pQueue->tail; ++i) {
            printf("\t%d", pQueue->array[i]);
        }printf("\tend\n");
    }

}

void freeQueue(queue *pQueue) {
    free(pQueue->array);
    free(pQueue);
}

queue *createQueue(int size) {
    queue *q;
    q=(queue*) malloc(sizeof(queue));                    //create struct and check if correctly
    if (q==NULL) printf("impossible create queue\n");
    else{
        q->maxSize=size;                   //initialized element
        q->head=q->tail=0;
        q->nEl=0;
        q->array=(int*) malloc(size* sizeof(int));    //create array and check if correctly
        if (q->array==NULL){
            printf("impossible create array\n");
            exit(1);
        }
        for (int i = 0; i < q->maxSize; ++i) {    //set el to zero
            q->array[i]=0;
        }
    }
    return q;
}

int dequeue(queue* pQueue) {
    int r;
    if(pQueue->nEl<=0){
        printf("queue is empty\n");
        r=-1;
    } else{
        r=pQueue->array[pQueue->head];                     //take value
        pQueue->array[pQueue->head]=0;                    //reset value to zero
        pQueue->head=(pQueue->head+1)%pQueue->maxSize;    //upgrade pointer and counter
        pQueue->nEl--;
    }
    return r;
}

int empty(queue* pQueue){
    int r;                    //using a return variables to permit to design a correct flowchart
    if(pQueue->nEl<=0) r=1;
    else r=0;
    return r;
}

void enqueue(queue* pQueue, int el) {
    if (pQueue->nEl>=pQueue->maxSize) {
        printf("queque is full\n");
    } else{
        pQueue->array[pQueue->tail] = el;                     //insert element upgrade element and counter
        pQueue->tail=(pQueue->tail+1)% (pQueue->maxSize);
        pQueue->nEl++;
    }
}
