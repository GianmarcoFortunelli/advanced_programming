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

void insertValue(DynArray* pStr) {
    int el, i, flg1; //support variables and flags
    printf("insert value and index to insert(val)\n");
    scanf("%d",&el);

    flg1= present(el,pStr);

    if ((pStr->size)>(pStr->nEl) && flg1==-1){   //if is still possible to insert
        for (i = 0; i < pStr->nEl; ++i) {    //search position
            if (el<pStr->array[i]) break;
        }
        for (int j = ((pStr->nEl)); j > i; --j) {
            pStr->array[j]=pStr->array[j-1];
        }
        (pStr->nEl)++;  // add an element
        (pStr->array)[i]=el;   //insert the element
    }
    else
        printf("error in the insert\n");
}

int present(int el, DynArray* pStr) {                 //I could reduce algorithms complexity at the o(log(n)) instead of o(n)
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
        for (int i = 0; i < (pStr->nEl); ++i) {
            printf("\t%d",(pStr->array)[i]);
        }
        printf("\n");
    }
}

DynArray* createArray(int size){
    DynArray *p;
    p=(DynArray*)malloc(sizeof(DynArray));
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
