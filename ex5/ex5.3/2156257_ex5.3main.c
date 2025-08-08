#include "other.h"


int main() {
    complex q1, q2, q;  // 2 number and a support variables

    q1=initCom();   //initialized the number
    q2=initCom();

    printf("First number: %d real part, %d imaginary part\n", q1.real,q1.im);  //fun to print real and imaginary part for each number
    printf("Second number: %d real part, %d imaginary part\n", q2.real,q2.im);

    q=add(q1,q2);  //sum the two number
    printf("the sum of the 2 number is %d+i(%d)\n", q.real,q.im);

    q=diff(q1,q2);  //diff the two number
    printf("the difference of the 2 number is %d+i(%d)\n", q.real,q.im);

    q=prod(q1,q2);  //product of the two number
    printf("the product of the 2 number is %d+i(%d)\n", q.real,q.im);

    return 0;
}

