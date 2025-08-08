#include <stdio.h>
#include "stdlib.h"

int main() {
    int r1,c1,r2,c2;   //row and column of each matrix
    printf("insert the size of the first matrix (row-column):\n");   //ask for size of matrix
    scanf("%d-%d", &r1,&c1);
    printf("insert the size of the second matrix (row-column):\n");
    scanf("%d-%d", &r2,&c2);
    if (c1!=r2){
        printf("not possible product\n");
        exit(1);
    }
    int m1[r1][c1],m2[r2][c2];    //decleare and fill the matrix
    printf("fill matrix one:\n");
    for (int i = 0; i < r1; ++i) {                         //first one
        for (int j = 0; j < c1; ++j) {
            printf("insert the element in %d row and %d column:\n",i, j);
            scanf("%d", &m1[i][j]);
        }
    }
    printf("fill matrix two:\n");
    for (int i = 0; i < r2; ++i) {                         //second one
        for (int j = 0; j < c2; ++j) {
            printf("insert the element in %d row and %d column:\n", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    int r[r1][c2];
    for (int i = 0; i < r1; ++i) {           //for each element of the result
        for (int j = 0; j < c2; ++j) {
            r[i][j]=0;
            for (int k = 0; k < r2; ++k) {          //sum all the product of row and column
                r[i][j]=r[i][j]+m1[i][k]*m2[k][j];
            }
        }
    }
    printf("The result is:\n");
    for (int i = 0; i < r1; ++i) {           //for each element of the result
        for (int j = 0; j < c2; ++j) {
            printf("%d ", r[i][j]);  //print the number
        }
        printf("\n");
    }
    return 0;
}
