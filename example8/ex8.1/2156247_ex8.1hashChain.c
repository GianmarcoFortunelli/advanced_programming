//
// Created by Huawei on 10/10/2022.
//

#include "hashChain.h"

void delete(const char *key) {
    hashEl *q= search(key);
    if (q==NULL) return;
    int index= hashFun(key);
    hashEl *p= tab[index];
    if (q==tab[index]){
        tab[index]=q->next;
        free(q);
        nElem--;
        return;}
    else{
        while (p->next!=q){
            p=p->next;}
        p->next=q->next;
        free(q);
        nElem--;
        return;
    }
}

hashEl *search(const char *key) {
    int index=hashFun(key);
    hashEl * p=tab[index];
    while (p!=NULL){
        if (strcmp(key, p->key)==0){
            return p;}
        p=p->next;}
    return NULL;
}

void printTab() {
    for (int i = 0; i < m; ++i) {
        hashEl *p =tab[i];
        while (p!=NULL){
            printf("%s : %d\n", p->key, p->data);
            p=p->next;
        }
    }
}

void insert(const char *key, int value) {
    int index=hashFun(key);
    hashEl * p=tab[index];
    while (p!=NULL){
        if (strcmp(key, p->key)==0){
            p->data=value;
            return;}
        p=p->next;}
    p=(hashEl*) malloc(sizeof(hashEl));
    p->key=key;
    p->data=value;
    p->next=tab[index];
    tab[index]=p;
    nElem++;
}

int hashFun(const char *key) {
    int ind=0;
    while (*key!='\0'){
        ind+=*key;
        ++key;}
    return ind%m;
}

void init() {
    for (int i = 0; i < m; ++i) {
        tab[i]=NULL;}
    nElem=0;
}

