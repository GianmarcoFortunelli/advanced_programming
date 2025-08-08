//
// Created by Huawei on 24/10/2022.
//

#include "exam.h"
#include <stdio.h>
#include <string.h>

void addTestingRes(const char *id, const char *res) {  //upload result of test on person hash table
    hashElPerson *p= searchHashPerson(id);    //find person data
    if (p==NULL) printf("Person not found\n");
    else {
        int result;
        if (strcmp(res, "positive") == 0) result = 1;   //analyze result
        else if (strcmp(res, "negative") == 0) result = 0;
        else{
            printf("result not valid\n");
            return;}

        if (p->val!=1) {   //if this persone before was not positive
            p->val = result;    //insert in the hashTable the result of the test

            if (result == 1) {     //if positive add to local hash table
                hashElLocation *q = searchHashLocation(p->location);   //search location
                if (q == NULL) insertHashLocation(1, p->location);   //insert 1 value if location not present
                else insertHashLocation(q->val + 1, p->location);   //else add one to positive
            }
        } else {
            p->val = result;    //insert in the hashTable the result of the test

            if (result == 0) {     //if negative remove to local hash table
                hashElLocation *q = searchHashLocation(p->location);   //search location
                insertHashLocation(q->val - 1, p->location);   //else remove one to positive
            }
        }
    }
}


void searchRegionRisk(const char *loc) {   //search by location on local hashtable
    hashElLocation* q= searchHashLocation(loc);
    if (q==NULL) printf("location:%s\n \trisk level: normal risk\n", loc);    //analyze level of risk and print info
    else{
        if (q->val==0) printf("location:%s\n \trisk level: normal risk\n", loc);
        else if(q->val<=3) printf("location:%s\n \trisk level: low risk\n", loc);
        else if (q->val>3 & q->val<5) printf("location:%s\n \trisk level: medium risk\n", loc);
        else if (q->val>5) printf("location:%s\n \trisk level:high risk\n", loc);
    }
}

void searchTestingRes(const char *id) {    //search by id on person hash table
    hashElPerson* p= searchHashPerson(id);
    if (p==NULL) printf("Person not found\n");
    else{
        printf("id:%s\n \tname:%s\n \ttesting location:%s\n \ttesting time:%s\n "               //print user info
               "\tresult:%d (0 negative 1 positive)\n",p->key, p->name,p->location,p->date,p->val);
    }
}

void addTestingInfo(const char *id, const char *name, const char *time, const char *loc) {
    insertHashPerson(-1,id, name, time, loc);     //insert in person hashTable with flag value as result
}

