//
// Created by Huawei on 10/10/2022.
//

#ifndef EX8_2_HASHOPEN_H
#define EX8_2_HASHOPEN_H

#include <stdio.h>
#include "stdlib.h"

typedef struct hashEL{
    int data;
    int key;
}hashEl;


typedef struct hashTab{
    int S;
    int N;
    struct hashEL **array;
}hashTab;


struct hashTab *createHashTab();

void insert(struct hashTab *pTab, int data, int key);

void printHash(struct hashTab *pTab);

#define SIZE 23;

struct hashEL *search(struct hashTab *pTab, int data);

int containKey(struct hashTab *pTab, int key);

void freeHash(struct hashTab *pTab);

int hashFun(struct hashTab *pTab, int key, int i);


#endif //EX8_2_HASHOPEN_H
