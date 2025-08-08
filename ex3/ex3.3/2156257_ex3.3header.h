//
// Created by Huawei on 05/09/2022.
//

#ifndef EX3_3_OTHER_H
#define EX3_3_OTHER_H

typedef struct {      //structure for each student --> create a dynamic array of this struct
    int id;
    char *name;
    char *surname;
}student;

void readFile(student **str, int *size);

void printList(student **str, int *size);

void removeStudent(student **str, int *size);

void addStudent(student **str, int *size);


#endif //EX3_3_OTHER_H
