#include <stdio.h>
#include "math.h"

typedef struct circle{  //adt to use
    int rad;  //radius
    int circ;  //circumference
    int area;  //area
}circle;

circle initCirc();

int main() {
    circle c1;   //declare adt
    printf("Initialize the circle\n");
    c1=initCirc();   //call fun to initialize
    printf("the circumference of the circle of radius %d is %d\n", c1.rad, c1.circ);  //print data
    printf("the area of the circle of radius %d is %d\n", c1.rad, c1.area);
    return 0;
}

circle initCirc() {
    int r; //support variable
    circle result;
    printf("insert radius of the circle (positive)\n");  //ask radius
    scanf("%d",&r);

    result.rad=r;         //insert and calculate data
    result.area=M_PI*r*r;
    result.circ=2*r*M_PI;
    return result;
}
