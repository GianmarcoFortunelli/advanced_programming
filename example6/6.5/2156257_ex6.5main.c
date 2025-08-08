#include <stdio.h>
#define MAX 3     //different from example (DIM=5) because in this way return same output


int queque[MAX+1];    //static array for the stack
int head=0, tail=0;        //index of operation

void enqueue(int el);
int empty();
int dequeue();

int main() {
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    printf("pop = %d\n", dequeue());
    printf("pop = %d\n", dequeue());
    printf("pop = %d\n", dequeue());
    printf("pop = %d\n", dequeue());
    return 0;
}

int dequeue() {
    int r;
    if(head==tail){
        printf("queue is empty\n");
        r=-1;
    } else{
        r=queque[head++];
        if (head==(MAX+1)) head=0;
    }
    return r;
}

int empty(){
    int r;                    //using a return variables to permit to design a correct flowchart
    if(head==tail) r=1;
    else r=0;
    return r;
}

void enqueue(int el) {
    if ((tail + 1) == head || (tail == MAX && head == 0)) {
        printf("queque is full\n");
    } else queque[tail++] = el;
    if (tail==(MAX+1)) tail=0;
}
