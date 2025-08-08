#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct {      //structure for each student --> create a dynamic array of this struct
    int id;
    char *name;
    char *surname;
}student;

void readFile(student **str, int *size);

void printList(student **str, int *size);

void removeStudent(student **str, int *size);

void addStudent(student **str, int *size);

int main() {
    student *str;
    int c=0, size=0;    //choice of user
    while (c!=5){
        printf("\nSelect an option:\n"
               "1) Add student\n"
               "2) Remove student\n"
               "3) Print the list of student\n"
               "4) Read student from file\n"
               "5) Exit\n");
        fflush(stdin);
        scanf("%d", &c);       //study choice and redirect to functions
        switch (c) {
            case 1:
                addStudent(&str,&size);
                break;
            case 2:
                removeStudent(&str, &size);
                break;
            case 3:
                printList(&str,&size);
                break;
            case 4:
                readFile(&str, &size);
                break;
            case 5:
                printf("closing programm...\n");  //confirm information
                break;
            default:
                printf("impossible choice\n");   //error information
        }
    }
    return 0;
}

void addStudent(student **str,int *size) {
    int id;                             //help variables
    char name[50], surname[50];
    student *p;                       //help pointer
    if (*size==0){  //if empty array
        p=(student*)malloc(sizeof(student));   //alloc memory
    } else{
        p=*str;
        p=(student*)realloc(p,(*size+1)*sizeof(student));  //else expand memory
    }
    if (p==NULL){                                    //message error if not possible
        printf("impossible add element");
        exit(1);
    }
    printf("insert data (id name surname):\n");
    scanf("%d %s %s", &id, name,surname);      //scan an int, 2 string
    p[*size].id=id;                                        //insert data with right size of memory for string and error message
    p[*size].name=(char*) malloc((strlen(name)+1)* sizeof(char));
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

void removeStudent(student **str, int *size) {
    int id, j=-1;  //id to find and flag if it is found
    printf("insert the id of the student to remove:\n");
    scanf("%d", &id);                             //asking the id to remove

    for (int i = 0; i < (*size)-1; ++i) {     //looking for the id
        if ((*str)[i].id==id) {      //find the id
            j = i;                 //change flag
            (*str)[i].id=(*str)[i+1].id;      //copy id of next student on the previous to delete
            free((*str)[i].name);    //release memory of name/surname of the student to delete
            (*str)[i].name=(*str)[i+1].name;   //copy the pointer of the next
            free((*str)[i].surname);
            (*str)[i].surname=(*str)[i+1].surname;
        }
        else if(j!=-1){
            (*str)[i].id=(*str)[i+1].id;         //if student found move the array of one position before
            (*str)[i].name=(*str)[i+1].name;
            (*str)[i].surname=(*str)[i+1].surname;
        }
    }
    *str=(student*) realloc(*str, ((*size)-1)* sizeof(student));   //release memory of last position of array
    *size-=1;   //decrement size
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
