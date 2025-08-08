#include <stdio.h>

#define VET_SIZE 5

void printArray(int vet[10]);

int main() {
    int vet[VET_SIZE], s=1, num, ind;//vector to elaborate, user choice, number to insert, index to elaborate

    for (int i = 0; i < VET_SIZE; ++i) {              //create the array
        printf("insert the element in %d index:\n", i);
        scanf("%d", &num);
        vet[i]=num;
    }

    printArray(vet);    //print the situation

    while (s!=3) {                                //elaborate the array
        printf("select your choice:\n"     //operation menu
               "\t1)Insert;\n"
               "\t2)Remove;\n"
               "\t3)Exit.\n");
        fflush(stdin);        //cleaning reading file for problem in selection during debugging
        scanf("%d", &s);
        switch (s) {              //analazing possibilities
            case 1:
                printf("write the number to insert and the index to insert (num-ind):\n");   //information for insertion
                scanf("%d-%d", &num, &ind);
                if (ind < 0 || ind >= VET_SIZE)                          //control if correct input
                    printf("error in the index to elaborate\n");
                else{
                    for (int i = VET_SIZE; i > ind; --i) {     //move the vector in the correct position
                        vet[i]=vet[i-1];
                    }
                    vet[ind]=num;                   //insert the number
                }
                printArray(vet);
                break;
            case 2:
                printf("write the index of the number to remove:\n");   //information for remove
                scanf("%d", &ind);
                if (ind < 0 || ind >= VET_SIZE)                          //check if correct
                    printf("error in the index to elaborate\n");
                else{
                    for (int i = ind; i < VET_SIZE-1; ++i) {
                        vet[i]=vet[i+1];              //move vector
                    }
                    vet[VET_SIZE-1]=0;           //insert the last zero
                }
                printArray(vet);
                break;
            case 3:
                printf("closing programm...\n");   //front end print
                break;
            default:
                printf("not valid selection\n");
                break;
        }
    }
    return 0;
}

void printArray(int vet[10]) {                  //function to print the vector from his pointer (first element)
    printf("The array contain:\n\t");
    for (int i = 0; i < VET_SIZE; ++i) {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}
