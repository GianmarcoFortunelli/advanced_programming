#include <stdio.h>
#include "bst.h"


int main() {
    bst* t1=NULL;
    t1=initBst(t1);

    insertBst(t1, 6);
    insertBst(t1, 3);
    insertBst(t1, 1);
    insertBst(t1, 4);
    insertBst(t1, 10);
    insertBst(t1, 8);
    insertBst(t1, 11);
    insertBst(t1, 9);
    insertBst(t1, 7);
    insertBst(t1, 12);


    printBst(t1);

    printf("min: %d\n", minimum(t1));
    printf("max: %d\n", maximum(t1));

    int x1=11, x2=10;
    bstNode* n=searchBst(t1, x1);
    bstNode* p=predecessorNode(n);
    printf("predecessor of %d: %d\n", x1, p->key);
    printf("predecessor of %d: %d\n", x2, predecessor(t1, x2));
    bstNode* s=successorNode(n);
    printf("successor of %d: %d\n", x1, s->key);
    printf("successor of %d: %d\n", x2, successor(t1,x2));
    deleteBst(t1,11);
    printBst(t1);
    return 0;
}

