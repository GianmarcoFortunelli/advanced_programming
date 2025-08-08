//
// Created by Huawei on 17/10/2022.
//

#ifndef EX9_1_BST_H
#define EX9_1_BST_H

#include <stdlib.h>
#include <stdio.h>

typedef int keyType;

typedef struct nodeTag{
    keyType key;
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

extern keyType minimum(bst* t);
extern keyType maximum(bst* t);
extern keyType searchBstVal(bst* t, keyType e);
extern keyType predecessor(bst* t, keyType e);
extern keyType successor(bst* t, keyType e);

extern bstNode *minimumNode(bstNode *t);
extern bstNode *maximumNode(bstNode *t);

extern bstNode *predecessorNode(bstNode *p);
extern bstNode *searchBst(bst *t, int e);
extern bstNode *successorNode(bstNode *p);

extern void insertBst(bst* t, keyType e);

extern void deleteBst(bst* t, keyType e);
extern void transplant(bst* t, bstNode *u, bstNode *v);

#endif //EX9_1_BST_H
