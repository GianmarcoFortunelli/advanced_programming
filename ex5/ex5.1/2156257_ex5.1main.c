#include "other.h"


int main() {
    int x, r, flag, r1, r2;  //choice and return parameters
    quad q1, q2, q;    //decleare struct


    q1.zer=0;   //zero degree //set default value to zero
    q1.fir=0;   //first degree
    q1.sec=0;   //second degree

    q1=iniQuad();   //insert the coefficient

    printf("insert the point to valutate the functions\n");
    scanf("%d",&x);
    r=val(q1,x);
    printf("the function in %d has value %d\n", x, r);

    q2=iniQuad();    //second fun to add

    printf("generate a new fun. adding the first 2\n");
    q=add(q1,q2);
    printf("the new fun. is %dx^2+%dx+%d\n",q.sec,q.fir,q.zer);

    printf("looking for roots of q1\n");
    flag=root(q1,&r1,&r2);  //functions to find root flag if not find =1
    if (flag==1)
        printf("no real roots\n");
    else
        printf("the root of the fun is %d and %d\n", r1, r2);

    return 0;
}

