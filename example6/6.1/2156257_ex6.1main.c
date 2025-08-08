#include <stdio.h>
#define MAX 5


int buff[MAX];    //static array for the stack
int ind=0;        //index of operation

void push(int el);
int empty();
int pop();

int main() {
    push(11);
    push(22);
    push(33);
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    return 0;
}

int pop() {
    return (buff[--ind]);
}

int empty(){
    int r;                    //using a return variables to permit to design a correct flowchart
    if(ind==0) r=1;
    else r=0;
    return r;
}

void push(int el) {
    buff[ind++]=el;
}
