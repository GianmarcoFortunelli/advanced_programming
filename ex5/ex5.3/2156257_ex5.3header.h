//
// Created by Huawei on 09/09/2022.
//

#ifndef INC_5_3_OTHER_H
#define INC_5_3_OTHER_H

#include <stdio.h>

typedef struct complex{
    int real;  //real part
    int im;    //imaginary
}complex;

complex initCom();

complex add(complex complex1, complex complex2);

complex diff(complex complex1, complex complex2);

complex prod(complex complex1, complex complex2);


#endif //INC_5_3_OTHER_H
