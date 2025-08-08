#include <stdio.h>

#define N 10 //dimension of array

int main() {
    int v[10], de=1, in=1, first=1, pos=0, neg=0, zeros=0;  //vector of element, variables for order decreasing and increasing, variables for first item, number of positive negative zeros
    for (int i = 0; i < N; ++i) {                                    //loop for make the arrey from keyboard
        printf("\nWrite the element in %d position:", i);
        scanf("%d", &v[i]);
        if (v[i]>0)                           //condition positive negative zero
            pos++;
        else if (v[i]<0)
            neg++;
        else
            zeros++;
        if (first==1)         //take off first element to comparison with the previous
            first=0;
        else{
            if (v[i]>=v[i-1]){de=0;}   //if the element before is smaller or equal array not decreasing
            if (v[i]<=v[i-1]){in=0;}
        }

    }
    printf("\nIn the array there is/are %d positive number, %d negative number, %d zeros\n", pos, neg, zeros);  //output information
    if (de==0 && in==0)
        printf("The array hasn't an order\n");
    else if (de==1)
        printf("The array has decreasing order\n");
    else
        printf("The array has increasing order\n");
    return 0;
}
