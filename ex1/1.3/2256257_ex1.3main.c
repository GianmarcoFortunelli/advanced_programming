#include <stdio.h>

int main() {
    int n, c; //variables for size of square and the choice of case
    printf("insert the size of square and the case to make (size-case):\n");
    scanf("%d-%d",&n,&c);

    switch (c) {
        case 1:
            for (int i = 0; i < n; ++i) {         //print a square of *
                for (int j = 0; j < n; ++j) {
                    printf("*");             //all the line
                }
                printf("\n");               //when finish go in the other line
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i) {         //print a square of *
                for (int j = 0; j < n; ++j) {
                    if (i==0 || i==n-1 || j==0 ||j==n-1) //if in the border
                    printf("*");
                    else
                        printf(" ");
                }
                printf("\n");               //when finish go in the line
            }
            break;
        case 3:
            for (int i = 0; i < n; ++i) {         //print a square of *
                for (int j = 0; j < n; ++j) {
                    if (j<=i)
                    printf("*");             //if under the diagonal
                    else
                        printf(" ");
                }
                printf("\n");               //when finish go in the line
            }
            break;
        default:
            printf("error in the selection of case\n");
    }


    return 0;
}
