//
// Created by Huawei on 12/09/2022.
//

#include "other.h"

void removeValue(int pInt[100], int *pNEl) {
    int el, flg1; //support variables and flags
    printf("insert value to remove (val)\n");
    scanf("%d",&el);

    flg1=present(el,pInt,pNEl);      //flag checking container definition (no holes no repetition)

    if (flg1!=-1){
        for (int i = flg1; i < (*pNEl-1); ++i) {
            pInt[i]=pInt[i+1];
        }
        pInt[*pNEl]=0;
        (*pNEl)--;
    }
    else
        printf("error in the remove\n");
}


void writeValue(int pInt[100], int *pNEl) {
    int el, ind, flg1;
    printf("insert value and index to insert(val ind)\n");
    scanf("%d %d",&el,&ind);

    flg1=present(el,pInt,pNEl);
    if (ind>=0 && ind<=*pNEl && ind<size && flg1==-1){
        pInt[ind]=el;
        (*pNEl)++;
    }
    else
        printf("error in the insert\n");
}


void insertValue(int pInt[100], int *pNEl) {
    int el, ind, flg1; //support variables and flags
    printf("insert value and index to insert(val ind)\n");
    scanf("%d %d",&el,&ind);

    flg1=present(el,pInt,pNEl);      //flag checking container definition (no holes no repetition)

    if (ind>=0 && ind<=*pNEl && ind<size && flg1==-1){
        for (int i = *pNEl; i > ind; --i) {
            pInt[i]=pInt[i-1];
        }
        pInt[ind]=el;
        (*pNEl)++;
    }
    else
        printf("error in the insert\n");
}

int present(int el, int *pInt, int *pNel) {
    for (int i = 0; i < *pNel; ++i) {
        if(pInt[i]==el)
            return i;        //return index if element is already present in the array
    }
    return -1;
}

void printArray(int pInt[100], int *pNEl) {
    if (*pNEl==0) printf("empty array\n");
    else{
        printf("the array contains:\n");
        for (int i = 0; i < *pNEl; ++i) {
            printf("\t%d",pInt[i]);
        }
        printf("\n");
    }
}

