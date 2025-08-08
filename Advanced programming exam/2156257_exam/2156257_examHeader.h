//
// Created by Huawei on 24/10/2022.
//

#ifndef EXAM2_EXAM_H
#define EXAM2_EXAM_H

#include "hashChain.h"

void addTestingInfo(const char *id, const char *name, const char *time, const char *loc); //add person info to hashtable of person

void searchTestingRes(const char *id);    //return person info by id

void searchRegionRisk(const char *loc);   //return risk level by location name

void addTestingRes(const char *id, const char *res);  //add test result to hashtable of person and upload location hashTable


#endif //EXAM2_EXAM_H
