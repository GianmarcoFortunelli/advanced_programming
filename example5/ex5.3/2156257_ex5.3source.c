//
// Created by Huawei on 17/09/2022.
//

#include "other.h"

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
    node *p = *pHead, *q;
    if (ind > listLength(pHead)+1 || ind <= 0)   //considering ind the effective element (head is not element I have to consider +1 of each comparison)
        printf("wrong index");
    else {
        while (pos != ind - 1) {
            p = p->next;   //looking for correct pos
            pos += 1;
        }
        q = p->next;   //q is the element to delete
        p->next = q->next;   //link the previous element to the next
        free(q);
    }
}

void indexInsert(struct node **pHead, int ind, int el) {
    ind=ind+1;
    if (ind > listLength(pHead)+1 || ind <= 0)   //considering ind the effective element (head is not element I have to consider +1 of each comparison)
        printf("wrong index");
    else {
        int pos = 0;
        node *new, *p = *pHead;
        new = (node *) malloc(sizeof(node));    //creat a new node
        if (new == NULL) {
            printf("impossible add node");  //check is created correctly
            exit(1);
        } else {
            new->val = el;   //insert value
            while (pos != ind-1) {
                p = p->next;   //looking for correct pos
                pos += 1;
            }
            new->next = p->next;   //link the next element to the new
            p->next = new;   //link the new element to previous
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


void creatList(struct node **pHead) {
    node *p;
    p = (node *) malloc(sizeof(node));   //create head
    if (p == NULL) {
        printf("impossible create list\n");
        exit(1);
    } else {
        p->val = 0;    //flag value
        p->next = p;  //head is also tail so point to head
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
        *pHead=NULL;
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
        (*pHead)->next=(*pHead);
    }
}

void checkEmpty(struct node **pHead) {
    if(*pHead==NULL)
        printf("The list doesn't exist\n");
    else if ((*pHead)->next==*pHead)
        printf("The list is empty\n");
    else
        printf("The list isn't empty\n");
}

