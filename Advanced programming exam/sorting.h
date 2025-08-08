//
// Created by Huawei on 26/09/2022.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <stdio.h>
#include "stdlib.h"

//libraries with some sorting algorithms and a printing functions
//must have an array of integer and size of array

extern void printSortedArray(int *pInt, int size);

extern void selectionSort(int *pA, int size);                                        // selection (time complexity O(n^2)

extern void insertionSort(int *pA, int size);                                        //insertion (time complexity O(n^2)

extern void countingSort(int **pA, int size);                                       //counting (time complexity O(k+n)

extern void bubbleSort(int *pA, int size);                                          //bubble (time complexity O(n^2)

extern void shellSort(int *pA, int size);                                           //shell (time complexity O(n^2)

extern void insertionSort2(int *pA, int start, int size, int inc);

extern void mergeSort(int *pA, int size);                                          //merge (time complexity O(nlogn)

extern void recMerge(int *pA, int *pB, int first, int last);

extern void mergeArr(int *pA, int *pB, int first, int mid, int last);

extern void quickSort(int *pA,int start, int end);                                 //quick (time complexity O(nlon)   BEST TO USE

extern void swap(int *pA, int i, int j);

extern int partition(int *pA, int l, int r, int pivot);

#endif //SORTING_SORTING_H
