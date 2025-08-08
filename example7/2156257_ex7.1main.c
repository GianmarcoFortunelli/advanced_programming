#include "sorting.h"

int main() {
    int size, *a, choice;   //variable for choice, dimensione and pointer to array
    printf("insert the dimension of the array to sort:\n");
    scanf("%d",&size);
    a=(int*)malloc(size*sizeof(int));
    printf("insert the array to sort:\n");
    for (int i = 0; i < size; ++i) {
        fflush(stdin);
        scanf("%d",&a[i]);
    }
    printf("select the sorting algorithm:\n"
           "\t1)selection (time complexity O(n^2))\n"
           "\t2)insertion (time complexity O(n^2))\n"
           "\t3)bubble (time complexity O(n^2))\n"
           "\t4)counting (time complexity O(k+n))\n"
           "\t5)merge (time complexity O(nlogn))\n"
           "\t6)quick (time complexity O(nlon))\n"
           "\t7)shell (time complexity O(n^2))\n");
    scanf("%d",&choice);

    switch (choice) {
        case 1:  selectionSort(a,size);  break;
        case 2:  insertionSort(a, size);  break;
        case 3:  bubbleSort(a, size);  break;
        case 4:  countingSort(&a, size); break;
        case 5:  mergeSort(a, size); break;
        case 6:  quickSort(a,0, size); break;
        case 7:  shellSort(a, size); break;
    }
    printArray(a, size);
    return 0;
}