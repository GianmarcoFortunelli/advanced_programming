//
// Created by Huawei on 10/10/2022.
//

#include "hashChain.h"
#include "stdlib.h"
#include "stdio.h"

hashEl* tab[m];

int nElem;

void delete(char *name) {
    hashEl *q= search(name);
    if (q==NULL) return;
    int index= hashFun(name);
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

hashEl *search(char *name) {
    int index=hashFun(name);
    hashEl * p=tab[index];
    while (p!=NULL){
        if (strcmp(p->name, name)==0){
            return p;}
        p=p->next;}
    return NULL;
}

void printTab() {
    for (int i = 0; i < m; ++i) {
        hashEl *p =tab[i];
        while (p!=NULL){
            printf("%d\t %s\t %s\n", p->id, p->name, p->surname);
            p=p->next;
        }
    }
}

void insert(const int id, char* name, char *surname) {
    int index=hashFun(name), ln;
    hashEl * p=tab[index];
    while (p!=NULL){
        p=p->next;}
    p=(hashEl*) malloc(sizeof(hashEl));
    p->id=id;
    ln= strlen(name);
    p->name=(char *) malloc((ln+1)*sizeof(char));
    if (p->name==NULL) exit(1);
    strcpy(p->name, name);
    ln= strlen(surname);
    p->surname=(char *) malloc((ln+1)*sizeof(char));
    if (p->name==NULL) exit(1);
    strcpy(p->surname, name);

    p->next=tab[index];
    tab[index]=p;
    nElem++;
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
    nElem=0;
}



