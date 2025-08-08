#include "other.h"



int main(){
    struct node* L=NULL;
    int c=0, l;
    while(c!=-1) {
        printMenu();
        printf("insert choice:\n");
        scanf("%d",&c);
        switch (c) {
            case -1:
                printf("Closing programm...\n"); break;
            case 1:
                creatList(&L); break;
            case 2:
                printList(&L); break;
            case 3:
                printListBack(&L); break;
            case 4:
                l=listLength(&L);
                if (l!=-1)
                    printf("The list length is %d",l); break;
            case 5: checkEmpty(&L); break;
            case 6: clearList(&L); break;
            case 7: insertEl(&L); break;
            case 8: delEl(&L); break;
            case 9: destroyList(&L);
            default:
                printf("wrong choice retry\n"); break;
        }
    }
    return 0;
}