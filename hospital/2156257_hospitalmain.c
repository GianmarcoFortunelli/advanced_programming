#include "fun.h"
#include "hashChain.h"


void insertDoc();



int main() {
    int c=0, nTik=1;    //choice parameters, number of doctors, number of ticket of the day
    init();         //pointer to array of doctor
    colorNode* head;                      //pointer to list of urgency
    insertDoc();   //initialize doc array
    initList(&head);     //and list
    while(c!=3){
        printf("select a choice:\n"    //option menu
               "\t1)insert patient\n"
               "\t2)next patient\n"
               "\t3)end of day\n");
        scanf("%d", &c);   //analyze choice
        switch (c) {
            case 1:  insertPat(&head, &nTik); break;
            case 2:  nextPat(&head); break;
            case 3:
                if(listEmpty(&head)==1){
                    printf("closing program and printing statistic\n");  //if list empty amble to close
                    printTab();}
                else{
                    printf("other patient to cure!\n");  //else finish the patience
                    c=0;
                }
                break;
            default:
                printf("wrong choice, retry\n");   //error control
        }
    }
    return 0;
}



void insertDoc() {
    int dim;
    char name[50];
    printf("Insert how many doctor are in the hospital:\n");
    scanf("%d", &dim);
    for (int i = 0; i < (dim); ++i) {
        printf("insert name of doc in room %d: ", i+1);             //insert data and info
        scanf("%s", name);
        insert(0, name);
    }
}