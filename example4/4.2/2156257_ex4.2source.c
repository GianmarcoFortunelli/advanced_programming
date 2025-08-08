//
// Created by Huawei on 12/09/2022.
//

#include "other.h"

void removeValue(DynArray* pStr) {
    int el, flg1; //support variables and flags
    printf("insert value to remove (val)\n");
    scanf("%d",&el);

    flg1=present(el, pStr);      //flag checking container definition (no holes no repetition)

    if (flg1!=-1){
        for (int i = flg1; i < ((pStr->nEl)-1); ++i) {
            (pStr->array)[i]=(pStr->array)[i+1];
        }
        (pStr->array)[(pStr->nEl)]=0;
        ((pStr->nEl))--;
    }
    else
        printf("error in the remove\n");
}


void writeValue(DynArray* pStr) {
    int el, ind, flg1;
    printf("insert value and index to insert(val ind)\n");
    scanf("%d %d",&el,&ind);

    flg1=present(el,pStr);
    if (ind>=0 && ind<=(pStr->nEl) && ind<(pStr->size) && flg1==-1){
        (pStr->array)[ind]=el;
        (pStr->nEl)++;
    }
    else
        printf("error in the insert\n");
}


void insertValue(DynArray* pStr) {
    int el, ind, flg1; //support variables and flags
    printf("insert value and index to insert(val ind)\n");
    scanf("%d %d",&el,&ind);

    flg1=present(el,pStr);      //flag checking container definition (no holes no repetition)

    if (ind>=0 && ind<=(pStr->nEl) && ind<(pStr->size) && flg1==-1){
        for (int i = (pStr->nEl); i > ind; --i) {
            (pStr->array)[i]=(pStr->array)[i-1];
        }
        (pStr->array)[ind]=el;
        (pStr->nEl)++;
    }
    else
        printf("error in the insert\n");
}

int present(int el, DynArray* pStr) {
    for (int i = 0; i < (pStr->nEl); ++i) {
        if((pStr->array)[i]==el)
            return i;        //return index if element is already present in the array
    }
    return -1;
}

void printArray(DynArray* pStr) {
    if (pStr->nEl==0) printf("empty array\n");
    else{
        printf("the array contains:\n");
        for (int i = 0; i < pStr->nEl; ++i) {
            printf("\t%d",(pStr->array)[i]);
        }
        printf("\n");
    }
}

DynArray* createArray(int size){
    DynArray *p;
    p->size=size;
    p->nEl=0;    //set empty
    p->array=(int*) malloc(size*sizeof(int)); //alloc array memory
    if ((p->array)==NULL){
        printf("Impossible create array\n");     //control if possible
        exit(1);
    }
    for (int i = 0; i < size; ++i) {    //set default value to zero
        (p->array)[i]=0;
    }
    return p;
}
