//
// Created by Huawei on 10/10/2022.
//

#include "hashOpen.h"

void freeHash(struct hashTab *pTab) {   //reales memory
    free(pTab->array);
    free(pTab);
}

valType containKey(struct hashTab *pTab, int key) { //look for the key
    int i=0, ind=0;
    while (i<pTab->S){
        ind= hashFun(pTab, key, i);     //get index
        if (pTab->array[ind]==NULL){
            printf("not found\n");
            return 0;
        } else if (pTab->array[ind]->key!=key) i++;   //if initial position not empty control next position   //CHANGE HERE IF CHANGE TYPES
        else if (pTab->array[ind]->key==key){
            printf("%d found\n", key);
            return pTab->array[ind]->data;}     //if found return data
    }
    return 0;
}

struct hashEL *search(struct hashTab *pTab, int key) {
    int i=0, ind=0;
    while (i<pTab->S) {
        ind = hashFun(pTab, key, i);  //check key if present and next position
        if (pTab->array[ind] == NULL) {
            printf("not found\n");
            return NULL;
        } else if (pTab->array[ind]->key != key)
            i++;
        else if (pTab->array[ind]->key==key){
            printf("key=%d\t data=%d\n", pTab->array[ind]->key,pTab->array[ind]->data);       //CHANGE HERE IF CHANGE TYPES
            return pTab->array[ind];            //return the element
        }
        printf("not found\n");
        return NULL;
    }
}

void printHash(struct hashTab *pTab) {
    printf("-------Hashtable:\n");
    for(int i=0; i<pTab->S; i++)
        if(pTab->array[i]!=NULL){
            printf("%d ", pTab->array[i]->key);                     //CHANGE HERE IF CHANGE TYPES
            printf(" %d\n", pTab->array[i]->data);
        }
    printf("-------end\n");
}

void insert(struct hashTab *pTab, valType data, keyType key) {
    int index;
    int i=0;
    int colFg=1;
    while (colFg & i<pTab->S){
        index=hashFun(pTab, key, i);      //find position
        if (pTab->array[index]!=NULL){
            colFg=1;
            i++;}
        else{                    //insert element
            colFg=0;
            hashEl *s;
            s=(hashEl*) malloc(sizeof(hashEl));
            s->data=data;                                           //CHANGE HERE IF CHANGE TYPES
            s->key=key;
            pTab->array[index]=s;
            pTab->N++;
        }
    }
    if(colFg==1) printf("Full struct\n");
    return;
}

int hashFun(struct hashTab *pTab, int key, int i) {    //from key to index   //CHANGE HERE IF CHANGE TYPES
    return (key+i)%pTab->S;
}

struct hashTab *createHashTab() {
    struct hashTab* hdt;
    hdt=(struct hashTab*) malloc(sizeof(hashTab));          //create the header struct
    if (hdt==NULL) return NULL;
    hdt->N=0;
    hdt->S=SIZE;
    hdt->array=(hashEl**) malloc(hdt->S* sizeof(hashEl));
    if (hdt->array==NULL) return NULL;
    for (int i = 0; i <hdt->S ; ++i) {       //set all to NULL
        hdt->array[i]=NULL;}
    return hdt;
}
