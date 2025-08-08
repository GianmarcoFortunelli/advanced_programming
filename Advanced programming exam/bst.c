//
// Created by Huawei on 17/10/2022.
//

#include "bst.h"


bst* initBst(bst* t){
    t=(bst*) malloc(sizeof(bst));
    if (t==NULL) printf("error in bst memory\n");
    t->root=NULL;
    return t;
}

void printBst(bst* t){
    printf("printing tree:\n");
    printNode(t->root, 0);
    printf("------end\n");
}

void printNode(bstNode* n, int level){
    //preorder print
    /*
    for (int i = 0; i < level; ++i) printf("\t");
    printf("%d\n", n->key);
    if (n->left) printNode(n->left, level+1);
    if (n->right) printNode(n->right, level+1);
    */
    //inorder print
    if (n->left) printNode(n->left, level+1);
    for (int i = 0; i < level; ++i) printf("\t");
    printf("%d\n", n->key);
    if (n->right) printNode(n->right, level+1);
    //postorder print
    /*
    if (n->left) printNode(n->left, level+1);
    if (n->right) printNode(n->right, level+1);
    for (int i = 0; i < level; ++i) printf("\t");
    printf("%d\n", n->key);
    */
}

bstNode *predecessorNode(bstNode *p) {
    if(p->left!=NULL) return maximumNode(p->left);
    bstNode *n=p->parent;
    while (n!=NULL & p==n->left){
        p=n;
        n=n->parent;
    }
    return n;
}

keyType predecessor(bst* t, keyType e){
    bstNode * n= searchBst(t, e);
    if(n==NULL){
        printf("Error: cannot find element\n");
        return 0;
    }
    n= predecessorNode(n);
    if(n==NULL){
        printf("Error: cannot find successor\n");
        return 0;
    }
    return n->key;
}

bstNode *searchBst(bst *t, int e) {
    if (t->root==NULL) printf("empty tree\n");
    bstNode* p=t->root;
    while (p!=NULL & p->key!=e){
        if (e<p->key) p=p->left;
        else p=p->right;
    }
    return p;
}

bstNode *successorNode(bstNode *p) {
    if(p->right!=NULL) return minimumNode(p->right);
    bstNode *n=p->parent;
    while (n!=NULL & p==n->right){
        p=n;
        n=n->parent;
    }
    return n;
}

keyType successor(bst* t, keyType e){
    bstNode * n= searchBst(t, e);
    if(n==NULL){
        printf("Error: cannot find element\n");
        return 0;
    }
    n= successorNode(n);
    if(n==NULL){
        printf("Error: cannot find successor\n");
        return 0;
    }
    return n->key;
}

keyType minimum(bst* t){
    if (t->root==NULL){
        printf("empty tree\n");
        return 0;
    }
    bstNode* p=t->root;
    while (p->left!=NULL) p=p->left;
    return p->key;
}

bstNode *minimumNode(bstNode *t){
    if (t==NULL){
        printf("empty tree\n");
        return 0;
    }
    bstNode* p=t;
    while (p->left!=NULL) p=p->left;
    return p;
}

keyType maximum(bst* t){
    if (t->root==NULL){
        printf("empty tree\n");
        return 0;
    }
    bstNode* p=t->root;
    while (p->right!=NULL) p=p->right;
    return p->key;
}

bstNode *maximumNode(bstNode *t){
    if (t==NULL){
        printf("empty tree\n");
        return 0;
    }
    bstNode* p=t;
    while (p->right!=NULL) p=p->right;
    return p;
}

void insertBst(bst* t, keyType e){
    bstNode* n=(bstNode*) malloc(sizeof(bstNode));
    if (n==NULL) printf("error in new node memory\n");
    n->key=e;
    n->right=NULL;
    n->left=NULL;
    n->parent=NULL;

    bstNode* p=NULL;
    bstNode* x=t->root;
    if(x==NULL){
        t->root=n;
        return;
    }
    while (x!=NULL){
        p=x;
        if(e<x->key) x=x->left;
        else x=x->right;
    }
    n->parent=p;
    if (e<p->key) p->left=n;
    else p->right=n;
}

void transplant(bst* t, bstNode *u, bstNode *v){
    if (t->root==NULL) return;
    if (u->parent==NULL) t->root=v;
    else if(u==u->parent->left) u->parent->left=v;
    else u->parent->right=v;
    if (v!=NULL) v->parent=u->parent;
}

void deleteBst(bst* t, keyType e){
    bstNode* n= searchBst(t, e);
    if(t->root==NULL) return;
    if(n->left==NULL) transplant(t, n, n->right);
    else if(n->right==NULL) transplant(t,n, n->left);
    else if(n->left!=NULL & n->right!=NULL){
        bstNode* x= minimumNode(n->right);
        if(x->parent!=n){
            transplant(t,x,x->right);
            x->right=n->right;
            x->right->parent=x;
        }
        transplant(t,n,x);
        x->left=n->left;
        x->left->parent=x;
    }
    free(n);
}