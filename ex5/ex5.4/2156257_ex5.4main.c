#include "other.h"


int main() {
    int s, *arr;

    arr=iniArray(&s);

    cleanArray(arr,s);

    insertArray(arr, s);
    insertArray(arr, s);
    insertArray(arr, s);

    printArray(arr, s);

    insertArray(arr, s);
    printArray(arr, s);

    free(arr);   //release memory

    return 0;
}
