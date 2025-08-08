//
// Created by Huawei on 05/09/2022.
//



#ifndef EX3_2_OTHER_H
#define EX3_2_OTHER_H

typedef struct {   //maybe I need to extern this
    int size;
    int *pointer;
}IArray;

extern void insertElement(IArray *structure);
extern void readValue(IArray *structure);
extern void printArray(IArray *structure);

#endif //EX3_2_OTHER_H
