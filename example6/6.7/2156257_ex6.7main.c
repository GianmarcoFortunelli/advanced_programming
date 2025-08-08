#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int maxSize;
    int head;
    int tail;
    int nEl;
    int incSize;
    int *array;
}queue;


void enqueue(queue* pQueue, int el);
int empty(queue* pQueue);
int dequeue(queue* pQueue);

queue *createQueue();

void freeQueue(queue *pQueue);

void printQueue(queue *pQueue);

int main() {
    queue* q;
    q=createQueue();
    printQueue(q);
    enqueue(q,11);
    enqueue(q,22);
    enqueue(q,33);
    enqueue(q,44);
    enqueue(q,55);
    enqueue(q,66);
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
    if (pQueue->head==pQueue->tail) printf("queue is empty\n");     //if the two pointer is the same the queue is empty
    else if(pQueue->head<pQueue->tail){
        for (int i = pQueue->head; i < pQueue->tail; ++i) {             //print from head to tail
            printf("\t%d", pQueue->array[i]);
        }
        printf("\tend\n");
    }

}

void freeQueue(queue *pQueue) {
    free(pQueue->array);
    free(pQueue);
}

queue *createQueue() {
    queue *q;
    q=(queue*) malloc(sizeof(queue));                    //create struct and check if correctly
    if (q==NULL) printf("impossible create queue\n");
    else{
        q->maxSize=4;      //initialized element
        q->incSize=2;
        q->head=q->tail=0;
        q->nEl=0;
        q->array=(int*) malloc(4* sizeof(int));    //create array and check if correctly
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
        pQueue->head++;                                   //upgrade pointer and counter
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
        int oldSize=pQueue->maxSize;
        pQueue->maxSize+=pQueue->incSize;
        int *s;  //support array
        s=(int*) malloc(pQueue->maxSize* sizeof(int));
        if (s==NULL){
            printf("impossible to upgrade queue\n");
            exit(1);
        }
        else{
            for (int i = 0; i < pQueue->incSize; ++i) {
                s[i+oldSize]=0; //set empty val to zero
            }
            for (int i = 0; i < oldSize; ++i) {
                s[i]=pQueue->array[i];
            }
            s[pQueue->tail]=el;
            pQueue->tail++;
            pQueue->nEl++;
            free(pQueue->array);
            pQueue->array=s;
        }
    } else{
        pQueue->array[pQueue->tail] = el;                     //insert element upgrade element and counter
        pQueue->tail=pQueue->tail+1;
        pQueue->nEl++;
    }
}
