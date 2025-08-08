//
// Created by Huawei on 10/10/2022.
//

#include "hashChain.h"
#include "stdlib.h"
#include "stdio.h"


hashEl* tab[m];

int n;


int search(char *key) {
    int index=hashFun(key);
    hashEl *p=tab[index];
    while (p!=NULL){
        if (strcmp(p->key, key)==0){
            return p->freq;}
        p=p->next;}
    return -1;
}
int compare(hashEl* a, hashEl* b){
    return b->freq - a->freq;
}

void printTab() {
    hashEl* ord=(hashEl*) malloc(n*sizeof(hashEl)), *current=ord;
    for (int i = 0; i < m; ++i) {
        hashEl *p=tab[i];
        while (p!=NULL){
            current->key=p->key;
            current->freq=p->freq;
            current++;
            p=p->next;
        }
    }
    qsort(ord, n, sizeof(hashEl), compare);

    for (int i = 0; i < n; ++i) {
        hashEl q=ord[i];
        printf("%s\t %d\n", q.key, q.freq);
        }
}

void insert(const int freq, char* key) {
    int index=hashFun(key);
    hashEl *p=tab[index];
    while (p!=NULL){
        if(strcmp(key, p->key)==0){
            p->freq=freq;
            return;}
        p=p->next;}
    p=(hashEl*) malloc(sizeof(hashEl));
    p->key= strdup(key);
    p->freq=freq;

    p->next=tab[index];
    tab[index]=p;
    n++;
}

int hashFun(char *name) {
    int ind=0;
    while (*name!='\0'){
        ind+=*name;
        ++name;}
    return (ind)%m;
}

void init() {
    for (int i = 0; i < m; ++i) {
        tab[i]=NULL;}
    n=0;
}

void printSorted(){

}




