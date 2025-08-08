#include "other.h"



int main() {
    int c=0, size, el, r;
    DynArray *p;
    printf("insert the size of the array to initialize:\n");
    scanf("%d", &size);
    p=createArray(size);

    while (c!=5) {                              //option menu
        printf("Choice an action:\n"
               "\t1)read the array\n"
               "\t2)insert value\n"
               "\t3)Remove value\n"
               "\t4)search value\n"
               "\t5)exit\n");
        scanf("%d",&c);
        switch (c) {                                                 //study option
            case 1:  printArray(p); break;
            case 2:  insertValue(p);  break;
            case 3:  removeValue(p); break;
            case 4:                                            //short code for print search result
                printf("insert number to search\n");
                scanf("%d",&el);
                r=present(el,p);
                if (r!=-1)
                    printf("element in %d position\n", r);
                else
                    printf("element not in array\n");
                break;
            case 5:  printf("closing program...");break;
            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}
