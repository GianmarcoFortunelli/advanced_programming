#include <stdio.h>
#include "other.h"
#include <time.h>

int main() {
    time_t t0, t1;
    double totTime;
    int num;
    printf("insert the number to calculate the series:\n");
    scanf("%d", &num);
    if (num==0)
            printf("the fibonacci series of 0 is 0\n");
    else if (num==1)
            printf("the fibonacci series of 1 is 1\n");
    else if (num>=2) {
        t0=clock();
        iterativeFibonacci(num);
        t1=clock();
        printf("the time of execution of iterative algorithms is %.3f\n", (double)(t1-t0)/CLOCKS_PER_SEC);
        t0=clock();
        recursiveFibonacci(num);
        t1=clock();
        printf("the time of execution of recursive algorithms is %.3f\n", (double)(t1-t0)/CLOCKS_PER_SEC);
    }
    else
        printf("not possible to calculate series of negative numbers\n");
    return 0;
}
