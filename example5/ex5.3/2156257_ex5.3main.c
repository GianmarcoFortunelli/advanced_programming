#include "other.h"

int main() {
    head *head=NULL;
    creatList(&head);

    indexInsert(&head,0,10);
    indexInsert(&head,1,20);
    indexInsert(&head,2,30);

    printList(&head);
    printf("the length of the list is %d\n", listLength(&head));
    printf("-----\n");

    indexInsert(&head,1,15);
    printList(&head);
    printf("-----\n");

    indexRead(&head,1);
    indexDelete(&head, 1);
    printList(&head);
    printf("-----\n");

    clearList(&head);
    printList(&head);
    printf("-----\n");

    destroyList(&head);
    printList(&head);
    printf("-----\n");

    return 0;
}
