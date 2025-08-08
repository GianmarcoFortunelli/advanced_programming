#include "other.h"


int main() {
    int array[size]={0}, nEl=0, c=0;
    for (int i = 0; i < size; ++i) {    //default value in the array
        array[i]=0;
    }

    while (c!=5) {                              //option menu
        printf("Choice an action:\n"
               "\t1)read the array\n"
               "\t2)insert value\n"
               "\t3)write value\n"
               "\t4)Remove value\n"
               "\t5)exit\n");
        scanf("%d",&c);
        switch (c) {                                                 //study option
            case 1:  printArray(array,&nEl); break;
            case 2:  insertValue(array,&nEl);  break;
            case 3:  writeValue(array,&nEl);  break;
            case 4:  removeValue(array,&nEl); break;
            case 5:  printf("closing program...");break;
        }
    }
    return 0;
}
