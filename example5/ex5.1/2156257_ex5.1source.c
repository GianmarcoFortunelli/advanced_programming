//
// Created by Huawei on 16/09/2022.
//

#include "other.h"

void indexRead(struct node **pHead, int ind) {
    node *p=*pHead;   //support pointer
    if(ind<0 || ind>=listLength(pHead))    //check if index is inside the list
        printf("wrong index\n");
    else{
        for (int i = 0; i < ind; ++i) {    //slides to correct position
            p=p->next;
        }
        printf("the element in %d position is %d\n", ind,p->val);  //print info
    }
}

int listLength(struct node **pHead) {
    int len=0;    //counter variables
    node *p=*pHead; //support pointer
    while (p!=NULL){   //while list not finish increment counter variable
        len+=1;
        p=p->next;   //slides to next el
    }
    return len;
}

void indexDelete(struct node **pHead, int ind) {
    int pos=0;
    node *p=*pHead, *q;
    while (pos!=ind-1) {
        p = p->next;   //looking for correct pos
        pos+=1;
    }
    q=p->next;   //q is the element to delete
    p->next = q->next;   //link the previous element to the next
    free(q);
}

void indexInsert(struct node **pHead, int ind, int el) {
    if (ind==0)
        headInsert(el,pHead);
    else if(ind>=listLength(pHead)||ind<0)
        printf("wrong index");
    else if(ind== listLength(pHead)-1)
        tailInsert(pHead, el);
    else {
        int pos=0;
        node *new, *p=*pHead;
        new = (node *) malloc(sizeof(node));    //creat a new node
        if (new == NULL) {
            printf("impossible add node");  //check is created correctly
            exit(1);
        } else {
            new->val = el;   //insert value
            while (pos!=ind-1) {
                p = p->next;   //looking for correct pos
                pos+=1;
            }
            new->next = p->next;   //link the next element to the new
            p->next = new;   //link the new element to previous
        }
    }
}

void tailInsert(struct node **pHead, int el) {
    node *new, *p=*pHead;  //support pointers
    p=*pHead;
    new=(node*) malloc(sizeof(node));    //creat a new node
    if (new==NULL){
        printf("impossible add node");  //check is created correctly
        exit(1);
    } else{
        new->val=el;   //insert value
        new->next=NULL;   //last element, no node to link
        while(p->next!=NULL){    //why in the slides are there a double check?? Is this enough?
            p=p->next;   //looking for last element
        }
        p->next=new;   //link the head as next node
    }
}

void printList(struct node **pHead) {
    node *p=*pHead;   //support pointer
    p=*pHead;
    printf("The list contain:");
    while (p!=NULL){    //while list not finished
        printf("  %d", p->val);   //print el and slides to next
        p=p->next;
    }
    printf("   end\n");
}

void headInsert(int el, struct node **pHead) {
    node *new;
    new=(node*) malloc(sizeof(node));    //creat a new node
    if (new==NULL){
        printf("impossible add node");  //check is created correctly
        exit(1);
    } else{
        new->val=el;   //insert value
        new->next=*pHead;   //link the head as next node
        *pHead=new;  //insert as the head of list
    }
}


void creatList(struct node **pHead) {
    *pHead=NULL; //create a null pointer
}
