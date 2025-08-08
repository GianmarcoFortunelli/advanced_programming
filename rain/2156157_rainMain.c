#include <stdio.h>
#include "hashChain.h"
#include "bst.h"

void addStation(char name[50], int rain);

void nearStation(char name[50], int rain);

bst* t;

typedef struct node{
    char* name;
    int rain;
}node;

int main() {
    int c=1, rain;     //help variable for choice
    char name[50];
    t=initBst(t);
    init();
    while (c!=0) {
        printf("Select menu':\n"
               "\t1)Add station\n"
               "\t2)Near station\n"
               "\t0) exit program\n");
        fflush(stdin);
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("get station name and rain quantity (name quantity):\n");
                fflush(stdin);
                scanf("%s %d", name, &rain);
                addStation(name, rain);
                break;
            case 2:
                printf("get station name and interval (name interval):\n");
                fflush(stdin);
                scanf("%s %d", name, &rain);
                nearStation(name, rain);
                break;
            case 3:
                printf("closing program...\n");
            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}

void nearStation(char name[50], int rain) {
    int quantity= searchHash(name);
    printf("%s %d\n", name, quantity);
    bstNode *current, *near, *start;
    start = searchBst(t, quantity);
    current=start;
    while (predecessorNode(current)!=NULL){
        near=predecessorNode(current);
        if(abs(start->key-near->key)<=rain){
            printf("%s %d\n", near->name, near->key);
            current=near;
        }else break;
    }
    current=start;
    while (successorNode(current)!=NULL){
        near= successorNode(current);
        if (abs(near->key-start->key)<=rain){
            printf("%s %d\n", near->name, near->key);
            current=near;
        }else break;
    }
}

void addStation(char name[50], int rain) {
    insertHash(rain, name);
    insertBst(t,rain,name);
}
