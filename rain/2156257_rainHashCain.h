//
// Created by Huawei on 10/10/2022.
//

#ifndef EXAMPLE8_1_HASHCHAIN_H
#define EXAMPLE8_1_HASHCHAIN_H

#include "stdlib.h"
#include "string.h"

//library with basic function to use hash table with chaining techniques
//change below type to change struct ecc

typedef char* keyType;
typedef int valType;

typedef struct hashEl {                                          //structure of each nome
    keyType key;                    //key type
    valType val;                      //value related to key
    struct hashEl * next;    //chaining to new element
}hashEl;

#define m 19       //define dimension of table (must be prime number near power of ten to avoid collision)

void init();    //create empty table

void insertHash(valType val, keyType key);   //insert element in the table

void printSortedTab();             //print table ordered by value

int searchHash(keyType key);      //search key in the table

int hashFun(keyType key);       //from key get index

int compare(hashEl *a, hashEl *b);     //ordering method

void printTab();           //printing tab without order

#endif //EXAMPLE8_1_HASHCHAIN_H
