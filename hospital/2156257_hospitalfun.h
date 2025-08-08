//
// Created by Huawei on 04/10/2022.
//

#ifndef HOSPITAL_FUN_H
#define HOSPITAL_FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashChain.h"

typedef struct patNode{      //struct for each patient
    int ticket;              //ticket number e pointer to next patient
    struct patNode* next;
}patNode;

typedef struct colorNode{    //struct for each color of urgency
    char colorName;          //color R Y G W
    struct patNode* head;    //head of list of patient
    struct colorNode* next;  //next urgency level
}colorNode;

typedef struct doc{   //data of each doc
    char *name;
    int nPat;
    int room;
}doc;


void initList(colorNode **pNode);

void printStat(doc **pDoc, int dim);

int listEmpty(colorNode **pNode);

void insertPat(colorNode** head, int* nTik);

void nextPat(colorNode **pNode);

int findPat(colorNode **pNode);


#endif //HOSPITAL_FUN_H
