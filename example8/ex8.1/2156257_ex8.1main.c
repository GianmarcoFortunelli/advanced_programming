#include <stdio.h>
#include "hashChain.h"


int main() {
    init();
    insert("smith", 98);
    insert("john", 87);
    insert("alice", 79);
    insert("joy", 85);
    printTab();
    printf("Research  -------\n");
    hashEl *d;
    d=search("john");
    printf("the searched grade: %d\n", d->data);
    printf("Delete  -------\n");
    delete("smith");
    printTab();
    return 0;
}