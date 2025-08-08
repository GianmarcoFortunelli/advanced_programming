#include <stdio.h>
#include "stdlib.h"

typedef struct {
    int size;
    int *pointer;
}IArray;

void printArray(IArray *structure);

void readValue(IArray *structure);

void insertElement(IArray *structure);

int main() {
    //define initial array
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

void insertElement(IArray *structure) {
    int num, ind;
    printf("insert the number and the index (num-ind):\n");     //ask for element
    scanf("%d-%d", &num, &ind);
    if(ind>=0 && ind<structure->size)   //check if possible
        structure->pointer[ind]=num;   //insert
    else
        printf("wrong index\n");
}

void readValue(IArray *structure) {
    int ind;
    printf("Insert the index to read:\n");   //ask information
    scanf("%d", &ind);
    if(ind>=0 && ind<structure->size)   //check if possible
        printf("The array in position %d contains %d\n", ind, structure->pointer[ind]);  //print information
    else
        printf("wrong index\n");
}

void printArray(IArray *structure) {
    printf("The array contain:\n");                   //print all the element of array
    for (int i = 0; i < structure->size; ++i) {
        printf("%d ",structure->pointer[i]);
    }
}
