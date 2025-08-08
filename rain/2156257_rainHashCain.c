//
// Created by Huawei on 10/10/2022.
//

#include "hashChain.h"
#include "stdlib.h"
#include "stdio.h"


hashEl* tab[m];

int n;


int searchHash(keyType key) {
    int index=hashFun(key);         //find by hash fun the relative position
    hashEl *p=tab[index];
    while (p!=NULL){
        if (strcmp(p->key, key)==0){    //check if same key                    //CHANGE HERE IF CHANGE KEY TYPE
            return p->val;}
        p=p->next;}  //else go away in the list of chain
    return 0;   //if not found return 0
}
int compare(hashEl* a, hashEl* b){  //compare function to QSORT change field if you want to change parameter of sorting
    return b->val - a->val;   //change order for ascending order
}

void printSortedTab() {
    hashEl* ord=(hashEl*) malloc(n*sizeof(hashEl)), *current=ord;  //create a new array with number of element
    for (int i = 0; i < m; ++i) {
        hashEl *p=tab[i];
        while (p!=NULL){          //copy each element in the array considering chaining
            current->key=p->key;
            current->val=p->val;
            current++;
            p=p->next;
        }
    }
    qsort(ord, n, sizeof(hashEl), compare);  //sort according to function

    for (int i = 0; i < n; ++i) {
        hashEl p=ord[i];
        printf("%s\t %d\n", p.key, p.val);   //print array                      //CHANGE HERE IF CHANGE TYPES
        }
}

void insertHash(valType val, keyType key) {
    int index=hashFun(key);    //get index
    hashEl *p=tab[index];
    while (p!=NULL){
        if(strcmp(key, p->key)==0){   //look in the position in index    //CHANGE HERE IF CHANGE KEY TYPE
            p->val=val;    //if same key upgrade element
            return;}
        p=p->next;}     //else create a new node in the list
    p=(hashEl*) malloc(sizeof(hashEl));
    p->key= strdup(key);                                          //CHANGHE HERE IF CHANGE KEY AND VALUE TYPE
    p->val=val;

    p->next=tab[index];    //upgrade parameters (head insertion)
    tab[index]=p;
    n++;
}

int hashFun(keyType key) {
    int ind=0;                   //function from key to index             CHANGE HERE IF CHANGE TYPE KEY
    while (*key!='\0'){
        ind+=*key;
        ++key;}
    return (ind)%m;
}

void init() {
    for (int i = 0; i < m; ++i) {     //create empty table
        tab[i]=NULL;}
    n=0;
}

void printTab() {
    for (int i = 0; i < m; ++i) {      //print all the table
        hashEl *p = tab[i];
        while (p != NULL) {
            printf("%s\t %d\n", p->key, p->val);
            p = p->next;
        }
    }
}