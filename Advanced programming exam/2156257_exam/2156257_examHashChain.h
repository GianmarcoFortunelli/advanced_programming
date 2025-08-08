//
// Created by Huawei on 10/10/2022.
//

#ifndef EXAMPLE8_1_HASHCHAIN_H
#define EXAMPLE8_1_HASHCHAIN_H

#include <stdlib.h>
#include <string.h>

//library with basic function to use hash table with chaining techniques

typedef char* keyType;
typedef int valType;

typedef struct hashElPerson {                                          //structure of each person
    keyType key;                    //id
    valType val;                      //test result
    char* name;
    char* date;
    char* location;
    struct hashElPerson * next;    //chaining to new element
}hashElPerson;

typedef struct hashElLocation {                                          //structure of each location
    keyType key;                    //name
    valType val;                      //number of positive
    struct hashElLocation * next;    //chaining to new element
}hashElLocation;

#define m 17       //define dimension of table (must be prime number near power of ten to avoid collision) for person
#define t 7        //for location

void initPerson();    //create empty table for person

void initLocation();    //for location

void insertHashPerson(valType val, keyType key, char* name, char* time, char *loc);   //insert person in the table

void insertHashLocation(valType val, keyType key);   //insert location in the table

hashElPerson* searchHashPerson(keyType key);      //search id in the table

hashElLocation* searchHashLocation(keyType key);      //search name in the table

int hashFunPerson(keyType key);       //from id get index

int hashFunLocation(keyType key);       //from name get index

void changeLocation(hashElPerson *person, char *newLoc);   //upgrade parameter if person change location

#endif //EXAMPLE8_1_HASHCHAIN_H
