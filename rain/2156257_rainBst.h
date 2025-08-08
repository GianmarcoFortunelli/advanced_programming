//
// Created by Huawei on 17/10/2022.
//

#ifndef EX9_1_BST_H
#define EX9_1_BST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int keyType1;

typedef struct nodeTag{
    keyType1 key;
    char* name;
    struct nodeTag* parent;
    struct nodeTag* left;
    struct nodeTag* right;
}bstNode;
typedef struct bstTag{
    bstNode* root;
}bst;

extern bst* initBst(bst* t);

extern void printBst(bst* t);
extern void printNode(bstNode* n, int level);

extern keyType1 minimum(bst* t);
extern keyType1 maximum(bst* t);
extern keyType1 searchBstVal(bst* t, keyType1 e);
extern keyType1 predecessor(bst* t, keyType1 e);
extern keyType1 successor(bst* t, keyType1 e);

extern bstNode *minimumNode(bstNode *t);
extern bstNode *maximumNode(bstNode *t);

extern bstNode *predecessorNode(bstNode *p);
extern bstNode *searchBst(bst *t, keyType1 e);
extern bstNode *successorNode(bstNode *p);

extern void insertBst(bst* t, keyType1 e, char* name);

extern void deleteBst(bst* t, keyType1 e);
extern void transplant(bst* t, bstNode *u, bstNode *v);

#endif //EX9_1_BST_H
