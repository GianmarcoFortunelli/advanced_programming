//
// Created by Huawei on 10/10/2022.
//

#include "hashChain.h"
#include "stdlib.h"


hashElPerson * tab1[m];    //person hash table
hashElLocation * tab2[t];   //location hash table

int n;  //number of element in person hashtable
int b;  //number of element in location hashtable



hashElPerson* searchHashPerson(keyType key) {
    int index=hashFunPerson(key);         //find by hash fun the relative position
    hashElPerson *p=tab1[index];
    while (p!=NULL){
        if (strcmp(p->key, key)==0){    //check if same key
            return p;}
        p=p->next;}  //else go away in the list of chain
    return NULL;   //if not found return NULL
}

hashElLocation* searchHashLocation(keyType key) {
    int index=hashFunLocation(key);         //find by hash fun the relative position
    hashElLocation *p=tab2[index];
    while (p!=NULL){
        if (strcmp(p->key, key)==0){    //check if same key
            return p;}
        p=p->next;}  //else go away in the list of chain
    return NULL;   //if not found return NULL
}

void insertHashPerson(valType val, keyType key,  char* name, char* time, char *loc) {
    int index=hashFunPerson(key);    //get index
    hashElPerson *p=tab1[index];
    while (p!=NULL){
        if(strcmp(key, p->key)==0){   //look in the position in index
            p->val=val;                           //if same key upgrade element
            p->name= strdup( name);
            p->date= strdup( time);
            if(strcmp(loc, p->location)!=0) {
                changeLocation(p, loc);
            }
            return;}
        p=p->next;}     //else create a new node in the list
    p=(hashElPerson *) malloc(sizeof(hashElPerson));
    p->key= strdup(key);
    p->val=val;
    p->name= strdup( name);
    p->date= strdup( time);
    p->location= strdup( loc);

    p->next=tab1[index];    //upgrade parameters (head insertion)
    tab1[index]=p;
    n++;
}

void changeLocation(hashElPerson *person, char *newLoc) {
    if(person->val==1){
        hashElLocation *q= searchHashLocation(person->location);
        insertHashLocation(q->val-1, person->location);
        person->location= strdup(newLoc);
    }
}

void insertHashLocation(valType val, keyType key) {
    int index=hashFunLocation(key);    //get index
    hashElLocation *p=tab2[index];
    while (p!=NULL){
        if(strcmp(key, p->key)==0){   //look in the position in index
            p->val=val;    //if same key upgrade element
            return;}
        p=p->next;}     //else create a new node in the list
    p=(hashElLocation *) malloc(sizeof(hashElLocation));
    p->key= strdup(key);
    p->val=val;

    p->next=tab2[index];    //upgrade parameters (head insertion)
    tab2[index]=p;
    b++;
}

int hashFunPerson(keyType key) {
    int ind=0;                   //function from id to index
    while (*key!='\0'){
        ind+=*key;
        ++key;}
    return (ind)%m;
}

int hashFunLocation(keyType key) {
    int ind=0;                   //function from name to index
    while (*key!='\0'){
        ind+=*key;
        ++key;}
    return (ind)%t;
}

void initPerson() {
    for (int i = 0; i < m; ++i) {     //create empty table
        tab1[i]=NULL;}
    n=0;
}

void initLocation() {
    for (int i = 0; i < t; ++i) {     //create empty table
        tab2[i]=NULL;}
    b=0;
}
