//
// Created by Huawei on 17/09/2022.
//

#include "other.h"

void prntDlt(head **pHead, int ind) {
    indexRead(pHead,ind);
    indexDelete(pHead,ind);
    printf("element deleted\n");
}


int locateElem(struct node **pHead, int el){
    node *p=(*pHead);
    int i = 0, r=0;
    if(p==NULL){
        printf("the list doesn't exist\n");
        r= -1;
    }
    else{
        p=p->next; //skip head value
        while (p!=(*pHead)){
            i++;
            if(p->val==el)
                r=i;
            p=p->next;
        }
    }
    return r; //I usually prefer to return only once for build the flowchart (r==0 if not present, ind if present, -1 if list not exist)
}

void indexRead(struct node **pHead, int ind) {
    node *p=(*pHead)->next;   //support pointer and slides over the head pointer
    if(ind<0 || ind>=listLength(pHead))    //check if index is inside the list
        printf("wrong index\n");
    else{
        for (int i = 0; i < ind; ++i) {    //slides to correct position
            p=p->next;
        }
        printf("the element in %d position is %d\n", ind,p->val);  //print info
    }
}

struct node* indexReadP(struct node **pHead, int ind){
    node *p=(*pHead);   //support pointer and slides over the head pointer
    if(ind > listLength(pHead) || ind <0) {   //check if index is inside the list
        printf("wrong Index\n");
        p==NULL;
    }
    else {
        for (int i = 0; i < ind; ++i) {    //slides to correct position
            p = p->next;
        }
    }
    return p;   //return the pointer at given position
}

int listLength(struct node **pHead) {
    int len = 0;    //counter variables
    node *p; //support pointer
    p= (*pHead)->next;  //not count the head node
    if (p == NULL) {
        printf("The list doesn't exist\n");
        return -1;
    } else {
        while (p != *pHead) {   //while list not return to head increment counter variable
            len += 1;
            p = p->next;   //slides to next el
        }
        return len;
    }
}

void indexDelete(struct node **pHead, int ind) {
    int pos = 0;
    ind=ind+1;
    node *p;
    if (ind > listLength(pHead)+1 || ind <= 0)   //considering ind the effective element (head is not element I have to consider +1 of each comparison)
        printf("wrong index");
    else {
        p= indexReadP(pHead, ind);
        if (p==NULL)
            printf("impossible find position\n");
        p->prev->next = p->next;   //q is the element to delete
        p->next->prev = p->prev;   //link the previous element to the next
        free(p);
    }
}

void indexInsert(struct node **pHead, int ind, int el) {
    ind=ind+1;
    if ((*pHead)==NULL){
        printf("list doesn't exist");
    }
    else{
        if (ind > listLength(pHead)+1 || ind <= 0)   //considering ind the effective element (head is not element I have to consider +1 of each comparison)
            printf("wrong index");
        else {
            node *new, *p;
            p= indexReadP(pHead,ind-1);
            if(p==NULL)
                printf("impossible find location\n");
            else {
                new = (node *) malloc(sizeof(node));    //creat a new node
                if (new == NULL) {
                    printf("impossible add node");  //check is created correctly
                    exit(1);}
                else {
                    new->val = el;   //insert value
                    new->prev=p;
                    new->next = p->next;   //link the next element to the new
                    p->next->prev=new; //next element previuos is the new node
                    p->next = new;   //link the new element to previous
                }
            }
        }
    }
}

void printList(struct node **pHead) {
    node *p;   //support pointer
    p = *pHead;
    if (p == NULL)
        printf("The list don't exist\n");
    else if (p->next == NULL)
        printf("empty list\n");
    else {
        printf("The list contain:");
        p = p->next; //first node is flag val
        while (p != (*pHead)) {    //while list not finished
            printf("  %d", p->val);   //print el and slides to next
            p = p->next;
        }
        printf("   end\n");
    }
}


void printListBack(struct node **pHead) {
    node *p;   //support pointer
    p = *pHead;
    if (p == NULL)
        printf("The list don't exist\n");
    else if (p->prev == NULL)
        printf("empty list\n");
    else {
        printf("The list contain:");
        p = p->prev; //first node is flag val, point to tail
        while (p != (*pHead)) {    //while list not finished
            printf("  %d", p->val);   //print el and slides to next
            p = p->prev;
        }
        printf("   head\n");
    }
}


void creatList(struct node **pHead) {
    node *p;
    p = (node *) malloc(sizeof(node));   //create head
    if (p == NULL) {
        printf("impossible create list\n");
        exit(1);
    } else {
        p->val = 0;    //flag value
        p->next = p->prev = p;  //head is also tail so point to head
        *pHead = p;   //return in the head position
    }
}

void destroyList(struct node **pHead) {
    node *p, *q;
    p=(*pHead);
    if(p==NULL)
        printf("The list doesn't exist\n");
    else{
        while (p->next!=(*pHead)){
            q=p->next;     //memorize next val
            free(p);   //delete the other one
            p=q;
        }
        free(*pHead); //delete the head
        *pHead=NULL;   //set the double pointer as a NULL value
    }
}


void clearList(struct node **pHead) {
    node *p, *q;
    p=*pHead;
    if(p==NULL)
        printf("The list doesn't exist\n");
    else if(p->next==NULL)
        printf("The list is already empty\n");
    else{
        p=p->next;    //make empty not destroy, head remain
        while (p->next!=(*pHead)){
            q=p->next;     //memorize next val
            free(p);   //delete the other one
            p=q;
        }
        (*pHead)->next=(*pHead)->prev=(*pHead);
    }
}

void checkEmpty(struct node **pHead) {
    if(*pHead==NULL)
        printf("The list doesn't exist\n");
    else if ((*pHead)->next==(*pHead) && (*pHead)->prev==(*pHead))
        printf("The list is empty\n");
    else
        printf("The list isn't empty\n");
}

