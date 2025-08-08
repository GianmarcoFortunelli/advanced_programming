#include <stdio.h>
#include <stdlib.h>
#include "hashChain.h"


void readFile();

int main() {
    hashEl* p;
    init();
    readFile();
    printTab();
    printf("searching element:\n");
    p=search("Homer");
    if (p!=NULL)
        printf("%d\t%s\t%s\n", p->id,p->name, p->surname);
    else
        printf("not found\n");
    return 0;
}

void readFile() {
    FILE *fp;            //pointer to input file
    char name[50],surname[50];
    int id;
    fp=fopen("input.txt", "r");         //opening file with control
    if (fp==NULL){
        printf("error opening file");
        exit(1);
    }
    while (!feof(fp)){
        fscanf(fp, "%d %s %s", &id, name, surname);   //scan an int, 2 string
        insert(id, name, surname);
    }
    fclose(fp);   //closing file
}


