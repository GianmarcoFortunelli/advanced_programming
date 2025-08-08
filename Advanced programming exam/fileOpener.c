#include "stdio.h"
#include "stdlib.h"


void readFile() {
    //before use change support variables type in declaration and in scanf, make the correct insertion function

    FILE *fp;                 //pointer to input file
    char name[50],surname[50];    //support variables
    int id;                     //support variables
    fp=fopen("input.txt", "r");         //opening file with control
    if (fp==NULL){
        printf("error opening file");
        exit(1);
    }
    while (!feof(fp)){
        fscanf(fp, "%d %s %s", &id, name, surname);   //scan an int, 2 string
        insert(id, name, surname);            //insert in the struct by command from other libraries
    }
    fclose(fp);   //closing file
}