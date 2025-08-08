//
// Created by Huawei on 10/10/2022.
//

#ifndef EXAMPLE8_1_HASHCHAIN_H
#define EXAMPLE8_1_HASHCHAIN_H

#include "stdlib.h"
#include "string.h"


typedef struct hashEl {
    char * key;
    int data;
    struct hashEl * next;    //chaining to new element
}hashEl;

#define m 71

hashEl * tab[m];

int nElem;



void init();

void insert(const char *key, int value);

void printTab();

hashEl *search(const char *key);

void delete(const char *key);


int hashFun(const char *key);



#endif //EXAMPLE8_1_HASHCHAIN_H
