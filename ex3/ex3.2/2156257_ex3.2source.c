//
// Created by Huawei on 05/09/2022.
//

#include "other.h"
#include <stdio.h>


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