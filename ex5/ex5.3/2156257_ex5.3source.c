//
// Created by Huawei on 09/09/2022.
//

#include "other.h"

complex prod(complex c1, complex c2) {
    int a,b,c,d;    //support variables
    complex result;
    a=c1.real;    //rename part for easier digit
    b=c1.im;
    c=c2.real;
    d=c2.im;

    result.real=a*c-b*d;    //product eq
    result.im=a*d+b*c;
    return result;
}

complex diff(complex c1, complex c2) {
    complex result;
    result.real=c1.real-c2.real;   //difference part by part
    result.im=c1.im-c2.im;
    return result;
}

complex add(complex c1, complex c2) {
    complex result;
    result.real=c1.real+c2.real;    //sum part by part
    result.im=c1.im+c2.im;
    return result;
}

complex initCom() {
    int r,i;
    complex result;
    printf("insert real and imaginary part (r i):\n");   //ask number
    scanf("%d %d",&r,&i);
    result.real=r;    //insert data
    result.im=i;
    return result;
}

