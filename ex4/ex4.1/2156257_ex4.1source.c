//
// Created by Huawei on 05/09/2022.
//

#include "other.h"
#include <stdio.h>
int fibonacci(int n);

void iterativeFibonacci(int num){
    int n1=1, n2=1, n3;
    for(int i=2;i<num;i++) {
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    printf("The Fibonacci series of %d is %d\n", num, n3);
}

void recursiveFibonacci(int num){
    int result;
    result=fibonacci(num);
    printf("The Fibonacci series of %d is %d\n", num, result);
}

int fibonacci(int n) {
    int risultato;
    if (n==0 || n==1)
        return n;
    else{
        risultato=fibonacci(n-1)+ fibonacci(n-2);
        return risultato;
    }
}