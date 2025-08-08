//
// Created by Huawei on 09/09/2022.
//

#ifndef EX5_1_OTHER_H
#define EX5_1_OTHER_H

#include "math.h"
#include <stdio.h>

typedef struct quad{    //adt to use
    int sec;
    int fir;
    int zer;
}quad;

quad iniQuad();

int val(quad quad1, int x);

quad add(quad quad1, quad quad2);

int root(quad quad1, int *pInt, int *pInt1);

#endif //EX5_1_OTHER_H
