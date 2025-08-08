//
// Created by Huawei on 26/09/2022.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <stdio.h>
#include "stdlib.h"

extern void printArray(int *pInt, int size);

extern void selectionSort(int *pA, int size);

extern void insertionSort(int *pA, int size);

extern void countingSort(int **pA, int size);

extern void bubbleSort(int *pA, int size);

extern void shellSort(int *pA, int size);

extern void insertionSort2(int *pA, int start, int size, int inc);

extern void mergeSort(int *pA, int size);

extern void recMerge(int *pA, int *pB, int first, int last);

extern void mergeArr(int *pA, int *pB, int first, int mid, int last);

extern void quickSort(int *pA,int start, int end);

extern void swap(int *pA, int i, int j);

extern int partition(int *pA, int l, int r, int pivot);

#endif //SORTING_SORTING_H
