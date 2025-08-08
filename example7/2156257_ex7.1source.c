//
// Created by Huawei on 26/09/2022.
//

#include "sorting.h"

void quickSort(int *pA, int start, int end) {
    int k;
    if(end<=start) return;
    else {
        int pivot = (start + end) / 2;
        swap(pA, pivot, end);
        k=partition(pA, start-1, end, pA[end]);
        swap(pA,k,end);
        quickSort(pA, start, k-1);
        quickSort(pA,k+1,end);
    }
}

int partition(int *pA, int l, int r, int pivot) {
    do {
        while(pA[++l]<pivot);
        while(pivot<pA[--r]);
        swap(pA, l, r);
    }while(l<r);
    swap(pA, l, r);
    return l;
}

void swap(int *pA, int i, int j) {
    int temp;
    temp=pA[i];
    pA[i]=pA[j];
    pA[j]=temp;
}

void mergeSort(int *pA, int size) {
    int *temp=(int*) malloc(size*sizeof(int));
    recMerge(pA, temp, 0, size);
    pA=temp;
}

void recMerge(int *pA, int *pB, int first, int last) {
    if (first<last){
        int mid=(first+last)/2;

        recMerge(pA,pB,first,mid);
        recMerge(pA,pB, mid+1, last);
        mergeArr(pA,pB,first, mid, last);
    }
}

void mergeArr(int *pA, int *pB, int first, int mid, int last) {
    int k=0, l=first, r=mid+1;
    while (l<=mid && r<=last){
        if (pA[l]<pA[r])
            pB[k++]=pA[l++];
        else pB[k++]=pA[r++];}
    while (l<=mid) pB[k++]=pA[l++];
    while (r<=last) pB[k++]=pA[r++];
    for (int i = 0; i < k; ++i) {
        pA[first+i]=pB[i];
    }
}

void shellSort(int *pA, int size) {
    for (int inc = size/2; inc >2; inc/=2) {
        for (int start = 0; start < inc; ++start) {
            insertionSort2(pA,start, size,inc);}}
    insertionSort2(pA, 0,size,1);
}

void insertionSort2(int *pA, int start, int size, int inc) {
    for (int i = start+inc; i < size; i+=inc) {
        for (int j = i; (j>=inc)&&(pA[j]<pA[j-inc]); j-=inc) {
            int temp=pA[j];
            pA[j]=pA[j-inc];
            pA[j-inc]=temp;
        }
    }
}

void bubbleSort(int *pA, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size-i; ++j) {
            if (pA[j]>pA[j+1]){
                int t=pA[j];
                pA[j]=pA[j+1];
                pA[j+1]=t;
            }
        }
    }
}

void countingSort(int **pA, int size) {
    int *sorted=(int *) malloc(size* sizeof(int)), *count=(int*) malloc(10*sizeof(int ));   //support array
    for (int i = 0; i < 10; ++i) {      //define counter array
        count[i]=0;}
    for (int i = 0; i < size; ++i) {      //number of element for each key
        count[(*pA)[i]]++;}
    for (int i = 1; i < 10; ++i) {      //calculate the index of insertion
        count[i]+=count[i-1];}
    for (int i = size-1; i >= 0; i--) {      //insert and upgrade index
        sorted[count[(*pA)[i]]-1]=(*pA)[i];
        count[(*pA)[i]]--;}
    free(*pA);
    *pA=sorted;                //insert the result in the initial array
    free(count);
}

void insertionSort(int *pA, int size) {
    for (int i = 0; i < size; ++i) {
        int ind=i, min=pA[ind];
        for (int j = i; j < size; ++j) {
            if (pA[j]<min){
                min=pA[j];
                ind=j;}
        }
        if(ind!=i){
            int temp=pA[i];
            pA[i]=pA[ind];
            pA[ind]=temp;
        }
    }
}

void selectionSort(int *pA, int size) {
    int key, j;
    for (int i = 1; i < size; ++i) {               //for each element look for the correct position
        key=pA[i];
        j=i-1;
        while (j>=0 && pA[j]>key){         //slides the other
            pA[j+1]=pA[j];
            j--;
        }
        pA[j+1]=key;            //insert the el
    }
}

void printArray(int *pInt, int size) {
    printf("Sorted array:\n");
    for (int i = 0; i < size; ++i) {
        printf("\t%d", pInt[i]);
    }
    printf("\tend\n");
}

