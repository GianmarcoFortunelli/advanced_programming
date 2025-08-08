#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {      //structure for each student --> create a dynamic array of this struct
    int id;
    char *name;
    char *surname;
}student;

void printList(student **str, int *size);

void readFile(student **str, int *size);

void sortStudent(student **str, int *size);

int main() {
    student *str;
    int size=0;
    readFile(&str, &size);
    printList(&str, &size);
    printf("sorting by ID...\n");
    sortStudent(&str, &size);
    printList(&str, &size);
    return 0;
}

int compare(const void* a, const void *b){
    return (((student*)a)->id - ((student*)b)->id);
}

void sortStudent(student **str, int *size) {
    qsort(*str, *size, sizeof(student), compare);   //sorting using quick sort
}


void readFile(student **str, int *size) {
    FILE *fp;            //pointer to input file
    student *p;                //help variables and pointer
    char name[50],surname[50];
    int id;
    p=*str;
    fp=fopen("input.txt", "r");         //opening file with control
    if (fp==NULL){
        printf("error opening file");
        exit(1);
    }
    while (!feof(fp)){
        p= realloc(p,(*size+1)*sizeof(student));   //while file not finish expand memory of struct for another student
        if (p==NULL){
            printf("impossible adding another student\n");
            exit(1);
        }
        fscanf(fp, "%d %s %s", &id, name, surname);   //scan an int, 2 string
        p[*size].id=id;
        p[*size].name=(char*) malloc((strlen(name)+1)* sizeof(char));   //insert data with right size of memory for string and error message
        if (p[*size].name==NULL)
            exit(2);
        strcpy(p[*size].name,name);
        p[*size].surname=(char*) malloc((strlen(surname)+1)* sizeof(char));
        if (p[*size].surname==NULL)
            exit(2);
        strcpy(p[*size].surname,surname);
        *str=p;                                           //upgrade pointer and size of the array of struct
        *size+=1;
    }
    fclose(fp);   //closing file
}


void printList(student **str, int *size) {
    if(*size==0)                             //control size
        printf("empty list");
    else {
        printf("The students are (id-name-surname):\n");
        for (int i = 0; i < *size; ++i) {                                 //print all element
            printf("%d\t%s\t%s\n", (*str)[i].id, (*str)[i].name, (*str)[i].surname);
        }
    }
}