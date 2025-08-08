//
// Created by Huawei on 10/10/2022.
//

#include "hashOpen.h"

void freeHash(struct hashTab *pTab) {
    free(pTab->array);
    free(pTab);
}

int containKey(struct hashTab *pTab, int key) {
    int i=0, ind=0;
    while (i<pTab->S){
        ind= hashFun(pTab, key, i);
        if (pTab->array[ind]==NULL){
            printf("not found\n");
            return 0;
        } else if (pTab->array[ind]->key!=key) i++;
        else if (pTab->array[ind]->key==key){
            printf("%d found\n", key);
            return pTab->array[ind]->data;}
    }
    return 0;
}

struct hashEL *search(struct hashTab *pTab, int key) {
    int i=0, ind=0;
    while (i<pTab->S) {
        ind = hashFun(pTab, key, i);
        if (pTab->array[ind] == NULL) {
            printf("not found\n");
            return NULL;
        } else if (pTab->array[ind]->key != key)
            i++;
        else if (pTab->array[ind]->key==key){
            printf("key=%d\t data=%d\n", pTab->array[ind]->key,pTab->array[ind]->data);
            return pTab->array[ind];
        }
        printf("not found\n");
        return NULL;
    }
}

void printHash(struct hashTab *pTab) {
    printf("-------Hashtable:\n");
    for(int i=0; i<pTab->S; i++)
        if(pTab->array[i]!=NULL){
            printf("%d ", pTab->array[i]->key);
            printf(" %d\n", pTab->array[i]->data);
        }
    printf("-------end\n");
}

void insert(struct hashTab *pTab, int data, int key) {
    int index;
    int i=0;
    int colFg=1;
    while (colFg & i<pTab->S){
        index=hashFun(pTab, key, i);
        if (pTab->array[index]!=NULL){
            colFg=1;
            i++;}
        else{
            colFg=0;
            hashEl *s;
            s=(hashEl*) malloc(sizeof(hashEl));
            s->data=data;
            s->key=key;
            pTab->array[index]=s;
            pTab->N++;
        }
    }
    if(colFg==1) printf("Full struct\n");
    return;
}

int hashFun(struct hashTab *pTab, int key, int i) {
    return (key+i)%pTab->S;
}

struct hashTab *createHashTab() {
    struct hashTab* hdt;
    hdt=(struct hashTab*) malloc(sizeof(hashTab));
    if (hdt==NULL) return NULL;
    hdt->N=0;
    hdt->S=SIZE;
    hdt->array=(hashEl**) malloc(hdt->S* sizeof(hashEl));
    if (hdt->array==NULL) return NULL;
    for (int i = 0; i <hdt->S ; ++i) {
        hdt->array[i]=NULL;}
    return hdt;
}
