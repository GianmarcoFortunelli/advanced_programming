//
// Created by Huawei on 10/10/2022.
//

#ifndef EXAMPLE8_1_HASHCHAIN_H
#define EXAMPLE8_1_HASHCHAIN_H

#include "stdlib.h"
#include "string.h"


typedef struct hashEl {
    char * key;
    int freq;
    struct hashEl * next;    //chaining to new element
}hashEl;

#define m 71



void init();

void insert(const int freq, char* key);

void printTab();

int search(char* key);


int hashFun(char* key);

void printSorted();

int compare(hashEl *a, hashEl *b);

#endif //EXAMPLE8_1_HASHCHAIN_H
