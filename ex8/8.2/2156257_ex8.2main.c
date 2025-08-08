#include <stdio.h>
#include "stdlib.h"
#include "hashChain.h"

int main() {
    FILE *fp= fopen("input.txt", "r");
    if (fp==NULL) exit(1);
    init();
    printf("reading file\n");
    while (1) {
        char input[255];
        int res;
        res = fscanf(fp, "%s", input);
        int n = search(input);
        insert(n + 1, input);
        if (res == EOF) break;
    }
    printTab();
    return 0;
}
