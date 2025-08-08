

#include "hashOpen.h"
int main() {
    struct hashTab *h;
    h=createHashTab();
    insert(h,1111,11);
    insert(h, 2222, 22);
    insert(h, 3333, 33);
    insert(h, 4444, 44);
    printHash(h);
    struct hashEL* s;
    s=search(h, 4400);
    s=search(h, 11);
    int a=containKey(h,11);
    a=containKey(h, 12);
    freeHash(h);
    return 0;
}
