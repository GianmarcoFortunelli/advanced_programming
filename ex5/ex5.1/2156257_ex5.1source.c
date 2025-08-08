//
// Created by Huawei on 09/09/2022.
//

#include "other.h"

int root(quad quad1, int *pInt, int *pInt1) {
    int flg=0;
    double d;
    d=(quad1.sec)^2-4*quad1.fir*quad1.fir;    //find delta
    if (d>=0){   //control possible solution
        *pInt=(-quad1.sec+(int)sqrt(d))/2+quad1.fir;   //find solution
        *pInt1=(-quad1.sec-(int)sqrt(d))/2+quad1.fir;
    } else flg=1;   //no solution flag
    return flg;
}

quad add(quad quad1, quad quad2) {
    quad result;
    result.zer=quad1.zer+quad2.zer;   //sum each coefficient of the quadratic
    result.fir=quad1.fir+quad2.fir;
    result.sec=quad1.sec+quad2.sec;
    return result;
}

int val(quad quad1, int x) {
    int result;
    result=quad1.zer+quad1.fir*x+quad1.sec*(x*x);    //valutate the function in the point x
    return result;
}

quad iniQuad() {
    int a, b, c;
    quad result;
    printf("insert coefficient of the new quadratic formula (a b c):\n");
    scanf("%d %d %d", &a, &b, &c);   //insert coefficent in the struct
    result.zer=c;
    result.fir=b;
    result.sec=a;
    return result;
}