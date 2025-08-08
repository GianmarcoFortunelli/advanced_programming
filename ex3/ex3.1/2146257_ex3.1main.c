#include <stdio.h>
#include "other.h"

int main() {
    int choice, num;
    printf("Choose if use iterative(0) or recursive (1):\n");
    scanf("%d", &choice);
    printf("insert the number to calculate the series:\n");
    scanf("%d", &num);
    if (num==0)
            printf("the fibonacci series of 0 is 0\n");
    else if (num==1)
            printf("the fibonacci series of 1 is 1\n");
    else if (num>=2) {
        switch (choice) {
            case 0:
                iterativeFibonacci(num);
                break;
            case 1:
                recursiveFibonacci(num);
                break;
            default:
                printf("wrong choice");
        }
    }
    else
        printf("not possible to calculate series of negative numbers\n");
    return 0;
}
