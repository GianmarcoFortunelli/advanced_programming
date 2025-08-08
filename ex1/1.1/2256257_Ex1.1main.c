#include <stdio.h>

//#define N 10 // number of element of the series

//use of iterative algorithms for less use of memory


int main() {
    int n1, n2, n3, N=10; //variables n3 for the new number, n2 and n1 for the 2 previous, N for the number of element of the series
    printf("Fibonacci series of %d number:\n", N);
    switch (N) {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("1\t1\n");
            break;
        default:
            n1=1;
            n2=1;
            printf("%d\t%d\t", n1, n2);
            for (int i = 0; i < N; ++i) {
                n3=n1+n2;
                printf("%d\t", n3);
                n1=n2;
                n2=n3;
            }
    }
    return 0;
}
