#include "other.h"


int main(){
    struct node* L;
    creatList(&L);
    headInsert(0,&L);     //index from 0 to length-1
    headInsert(10,&L);
    headInsert(30,&L);
    printList(&L);
    printf("--------\n");

    tailInsert(&L,20);
    tailInsert(&L,40);
    printList(&L);
    printf("--------\n");

    indexInsert(&L,2,25);
    printList(&L);
    printf("--------\n");

    indexDelete(&L,2);
    printList(&L);
    printf("--------\n");

    printf("length list is %d\n", listLength(&L));
    indexRead(&L,4);
    indexRead(&L,6);

    return 0;
}

