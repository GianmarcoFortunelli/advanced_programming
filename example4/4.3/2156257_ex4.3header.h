//
// Created by Huawei on 12/09/2022.
//

#ifndef EXAMPLE4_1_OTHER_H
#define EXAMPLE4_1_OTHER_H

#include <stdio.h>
#include "stdlib.h"

typedef struct DynArray{
    int size;
    int nEl;
    int *array;
}DynArray;

DynArray* createArray(int size);

void printArray(DynArray* pStr);

void insertValue(DynArray* pStr);

void removeValue(DynArray* pStr);

int present(int el, DynArray* pStr);

#endif //EXAMPLE4_1_OTHER_H
