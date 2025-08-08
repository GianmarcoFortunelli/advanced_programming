#include <stdio.h>
#include "other.h"

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
