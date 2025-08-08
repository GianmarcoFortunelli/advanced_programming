//
// Created by Huawei on 10/10/2022.
//

#ifndef EX8_2_HASHOPEN_H
#define EX8_2_HASHOPEN_H

#include <stdio.h>
#include "stdlib.h"

//library with basic function to use hash table with openadressing techniques
//change below type to change struct ecc

typedef int keyType;
typedef int valType;

#define SIZE 23;      //change tab dimension

typedef struct hashEL{    //element of tab
    valType data;
    keyType key;
}hashEl;


typedef struct hashTab{   //tab header
    int S;
    int N;
    struct hashEL **array;
}hashTab;


struct hashTab *createHashTab();    //creat hashTab struct

void insert(struct hashTab *pTab, keyType data, valType key);    //insert element in the tab

void printHash(struct hashTab *pTab);    //print table

struct hashEL *search(struct hashTab *pTab, valType data);   //search element in the table

valType containKey(struct hashTab *pTab, keyType key);   //search key in the table

void freeHash(struct hashTab *pTab);   //get tab empty

int hashFun(struct hashTab *pTab, keyType key, int i);    //form key to index with i iteration


#endif //EX8_2_HASHOPEN_H
