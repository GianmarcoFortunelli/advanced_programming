#include "other.h"



int main() {
    int c=0, size;
    DynArray *p;
    printf("insert the size of the array to inizialize:\n");
    scanf("%d", &size);
    p=createArray(size);

    while (c!=5) {                              //option menu
        printf("Choice an action:\n"
               "\t1)read the array\n"
               "\t2)insert value\n"
               "\t3)write value\n"
               "\t4)Remove value\n"
               "\t5)exit\n");
        scanf("%d",&c);
        switch (c) {                                                 //study option
            case 1:  printArray(p); break;
            case 2:  insertValue(p);  break;
            case 3:  writeValue(p);  break;
            case 4:  removeValue(p); break;
            case 5:  printf("closing program...");break;
        }
    }
    return 0;
}
