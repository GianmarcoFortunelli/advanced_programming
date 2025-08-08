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
        printf("the element in %d position is %d\n", ind,p->val);  //print info        //CHANGE HERE IG CHANGE TYPE
    }
}

int listLength(struct node **pHead) {
    int len = 0;    //counter variables
    node *p = *pHead; //support pointer
    if (p == NULL) {
        printf("The list doesn't exist\n");
        return -1;
    } else {
        while (p != NULL) {   //while list not finish increment counter variable
            len += 1;
            p = p->next;   //slides to next el
        }
        return len - 1;   //not count the head node
    }
}

void indexDelete(struct node **pHead, int ind) {
    int pos = 0;
    node *p = *pHead, *q;
    while (pos != ind - 1) {
        p = p->next;   //looking for correct pos
        pos += 1;
    }
    q = p->next;   //q is the element to delete
    p->next = q->next;   //link the previous element to the next
    free(q);
}

void indexInsert(struct node **pHead, int ind, valType el) {
    if (ind > listLength(pHead) || ind < 0)   //considering ind the effective element (head is not element I have to consider +1 of each comparison)
        printf("wrong index");
    else if (ind == listLength(pHead))
        tailInsert(pHead, el);
    else {
        int pos = 0;
        node *new, *p = *pHead;
        new = (node *) malloc(sizeof(node));    //creat a new node
        if (new == NULL) {
            printf("impossible add node");  //check is created correctly
            exit(1);
        } else {
            new->val = el;   //insert value
            while (pos != ind) {
                p = p->next;   //looking for correct pos
                pos += 1;
            }
            new->next = p->next;   //link the next element to the new
            p->next = new;   //link the new element to previous
        }
    }
}

void tailInsert(struct node **pHead, valType el) {
    node *new, *p = *pHead;  //support pointers
    p = *pHead;
    new = (node *) malloc(sizeof(node));    //creat a new node
    if (new == NULL) {
        printf("impossible add node");  //check is created correctly
        exit(1);
    } else {
        new->val = el;   //insert value
        new->next = NULL;   //last element, no node to link
        while (p->next != NULL) {    //why in the slides are there a double check?? Is this enough?
            p = p->next;   //looking for last element
        }
        p->next = new;   //link the head as next node
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
        while (p != NULL) {    //while list not finished
            printf("  %d", p->val);   //print el and slides to next                //CHANGE HERE IF CHANGE TYPE
            p = p->next;
        }
        printf("   end\n");
    }
}

void headInsert(valType el, struct node **pHead) {
    node *new;
    new = (node *) malloc(sizeof(node));    //creat a new node
    if (new == NULL) {
        printf("impossible add node");  //check is created correctly
        exit(1);
    } else {
        new->val = el;   //insert value
        new->next = *pHead;   //link the head as next node
        *pHead = new;  //insert as the head of list
    }
}


void creatList(struct node **pHead) {
    node *p;
    p = (node *) malloc(sizeof(node));
    if (p == NULL) {
        printf("impossible create list\n");
        exit(1);
    } else {
        p->val = 0; //flag value
        p->prev = NULL;     //null pointer in the link position
        p->next = NULL;
        *pHead = p;   //return in the head position
    }
}

void destroyList(struct node **pHead) {
    node *p, *q;
    p=*pHead;
    if(p==NULL)
        printf("The list doesn't exist\n");
    else if(p->next==NULL)
        printf("The list is already empty\n");
    else{
        while (p->next!=NULL){
            q=p->next;     //memorize next val
            free(p);   //delete the other one
            p=q;
        }
        pHead=NULL;
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
        while (p->next!=NULL){
            q=p->next;     //memorize next val
            free(p);   //delete the other one
            p=q;
        }
        (*pHead)->next=NULL;
    }
}

void delEl(struct node **pHead) {
    int ind;
    printf("insert the index of the element to delete:\n");
    scanf("%d",&ind);
    indexDelete(pHead,ind);
}

void checkEmpty(struct node **pHead) {
    if(*pHead==NULL)
        printf("The list doesn't exist\n");
    else if ((*pHead)->next==NULL)
        printf("The list is empty\n");
    else
        printf("The list isn't empty\n");
}

void printListBack(struct node **pHead) {
    node *p; //support pointer
    p=*pHead;
    if (p==NULL)
        printf("The list don't exist\n");   //check list status
    else if (p->next==NULL)
        printf("empty list\n");
    else {
        p = *pHead;
        while (p->next != NULL){   //look for the end of list
            p = p->next;}
        printf("List printed backwards:\n");
        while (p->prev != NULL) {
            printf("  %d", p->val);    //print value                             //CHANGE HERE IF OTHER TYPE
            p = p->prev;
        }
        printf("  head\n");
    }
}

