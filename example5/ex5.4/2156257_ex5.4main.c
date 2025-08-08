#include "other.h"

int main() {                      //check the double pointer each insertion ecc ecc
    head *head=NULL;
    creatList(&head);

    printf("-----INSERTION\n");
    for (int i = 0; i < 5; ++i)
        indexInsert(&head,i,5*(i+1));   //position from 0 to len-1

    printList(&head);
    printListBack(&head);
    printf("-----\n");

    printf("-----DELETE\n");    //create fun to print the value and delete
    prntDlt(&head,1);
    printList(&head);
    printListBack(&head);
    printf("-----\n");


    printf("-----LENGTH\n");
    printf("the length of the list is %d\n", listLength(&head));
    checkEmpty(&head);
    printf("-----\n");

    printf("-----INDEX READ\n");
    indexRead(&head,3);
    indexRead(&head,15);
    printf("-----\n");

    printf("-----CLEAR LIST\n");
    clearList(&head);
    checkEmpty(&head);
    destroyList(&head);
    printList(&head);
    printf("-----\n");

    return 0;
}
