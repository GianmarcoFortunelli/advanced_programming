//
// Created by Huawei on 10/10/2022.
//

#ifndef EXAMPLE8_1_HASHCHAIN_H
#define EXAMPLE8_1_HASHCHAIN_H

#include "stdlib.h"
#include "string.h"


typedef struct hashEl {
    char * surname;
    char *name;
    int id;
    struct hashEl * next;    //chaining to new element
}hashEl;

#define m 19



void init();

void insert(const int id, char* name, char *surname);

void printTab();

hashEl *search(char *name);

void delete(char *name);


int hashFun(char *name);

hashEl *readStudent(char* name);



#endif //EXAMPLE8_1_HASHCHAIN_H
