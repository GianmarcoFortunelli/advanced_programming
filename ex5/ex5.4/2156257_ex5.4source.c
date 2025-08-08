//
// Created by Huawei on 09/09/2022.
//

#include "other.h"


void printArray(int *pInt, int s) {
    printf("The array contains:");
    for (int i = 0; i < s; ++i) {
        printf("%d ", pInt[i]);                //print all value
    }
    printf("\n");
}

void cleanArray(int *pInt, int s) {
    for (int i = 0; i < s; ++i) {
        pInt[i]=0;                //set all value to zero
    }
}

void insertArray(int *pInt, int size) {
    int ind, val;
    printf("insert the index and the value to insert (ind val)\n");
    fflush(stdin);
    scanf("%d %d", &ind, &val);
    if (ind>=0 && ind < size){   //if index internal in array
        if (pInt[ind]==0)
            pInt[ind]=val;     //insert value
        else{
            for (int i = size-1 ;i > ind; --i) {   //shift array
                pInt[i]=pInt[i-1];
            }
            pInt[ind]=val;
        }
    }
    else printf("wrong index\n");
}

int *iniArray(int *s) {
    int *tmp;
    printf("Insert the size of array\n");  //ask size
    fflush(stdin);
    scanf("%d", s);
    tmp=(int*) malloc((*s)*sizeof(int));   //dynamic array
    if (tmp==NULL){
        printf("impossible create the array\n");
        exit(1);
    }
    return tmp;
}
