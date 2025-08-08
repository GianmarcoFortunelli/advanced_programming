#include <stdio.h>
#include <stdlib.h>
#include "other.h"



int main() {
    int size,*v;   //help variables for insert data
    IArray str;    //struct to use
    printf("Define the size of the array:\n");   //ask for the size
    scanf("%d", &size);
    str.size=size;                 //set in the struct
    v=(int *) malloc(size*sizeof(int));   //alloc memory
    if (v==NULL){
        printf("impossible to create array\n");  //check if possible
        exit(1);
    }
    str.pointer=v;     //insert in struct

    for (int i = 0; i < size; ++i) {   //set all the initial value of the vector to zero
        str.pointer[i]=0;
    }

    int c;    //choice of user
    while (c!=4){
        printf("\nSelect an option:\n"
               "1) insert value\n"
               "2) read index value\n"
               "3) print array\n"
               "4) exit\n");
        fflush(stdin);
        scanf("%d", &c);       //study choice and redirect to functions
        switch (c) {
            case 1:
                insertElement(&str);
                break;
            case 2:
                readValue(&str);
                break;
            case 3:
                printArray(&str);
                break;
            case 4:
                printf("closing programm...\n");  //confirm information
                break;
            default:
                printf("impossible choice\n");   //error information
        }
    }
    return 0;
}
