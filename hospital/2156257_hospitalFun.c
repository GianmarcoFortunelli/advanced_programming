//
// Created by Huawei on 04/10/2022.
//

#include "fun.h"


void nextPat(colorNode **pNode) {
    int tik;
    char name[50];
    printf("insert the doctor free:\n");   //ask for free doc
    fflush(stdin);
    gets(name);
    int p=search(name);
    if (p==-1)
        printf("error in doctor insertion\n");   //control if exist
    else {
        insert(p+1, name);   //upload statics
        tik=findPat(pNode);
        if (tik!=-1){
            printf("patient %d with doctor %s\n", tik, name);}  //print info
        else
            printf("empty list\n");
    }
}

int findPat(colorNode **pNode) {
    int tik=-1, found=0, n=0;
    colorNode *p=*pNode;
    patNode *q;
    while(found==0 & n<4) {    //until not found and color not finish
        if (p->head != NULL) {   //if same level urgency list exist
            q = p->head;      //take first element as next patient
            found = 1;
            tik = q->ticket;
            p->head = q->next;    //delete from the list and release memory
            free(q);
        }
        p=p->next;  //else go to next color
        n += 1;  //not go over the last color
    }
    return tik;
}

void insertPat(colorNode** head, int* nTik) {
    char col;
    int n=0, c=0;
    colorNode *p=*head;
    patNode *newPat, *q;
    printf("insert color (R/Y/G/W): \n");   //insert level of urgency
    fflush(stdin);
    scanf("%c",&col);
    while (c==0& n<4){   //find in exist and not go over
        if(p->colorName==col)
            c=1;
        p=p->next;
        n+=1;}
    if(c==0)
        printf("wrong urgency color\n");
    else {
        newPat = (patNode *) malloc(sizeof(patNode));   //create a new patient node
        newPat->next = NULL;
        printf("your ticket is %d\n", (*nTik));     //insert and print info
        newPat->ticket = (*nTik)++;
        if (p->head == NULL) {   //if first element insert in head of list
            p->head = newPat;
        } else {
            q = p->head;
            while (q->next != NULL) //else in the tail
                q = q->next;
            q->next = newPat;
        }
    }
}

int listEmpty(colorNode **pNode) {
    colorNode *p;
    int empty=1;
    p=*pNode;
    while (p->next!=NULL){   //control if not finish the patient in the list
        if(p->head!=NULL)
            empty=0;   //turn off if some list not empty
        p=p->next;
    }
    return empty;
}

void printStat(doc **pDoc, int dim) {
    printf("statistic of doctor:\n");
    for (int i = 0; i < dim; ++i) {
        printf("\troom:%d\tname:%s\tnPat:%d\n", i+1, (*pDoc)[i].name, (*pDoc)[i].nPat);
    }
}

void initList(colorNode **pNode) {
    char color[4]={'R','Y','G','W'};
    colorNode *new, *prev;
    new=(colorNode*) malloc(sizeof(colorNode));   //create a new urgency level
    if(new==NULL){
        printf("impossible create list\n");
        exit(20);
    }
    new->head=NULL;            //insert info
    new->colorName=color[0];
    new->next=NULL;
    *pNode=new;
    prev=new;
    for (int i = 1; i < 4; ++i) {
        new=(colorNode*) malloc(sizeof(colorNode));
        if(new==NULL){
            printf("impossible create list\n");
            exit(20);
        }
        new->head=NULL;
        new->colorName=color[i];
        new->next=NULL;
        prev->next=new;
        prev=new;
    }
}

