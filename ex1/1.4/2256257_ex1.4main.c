#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;    //pointer to file
    char line[100];     //str for copy
    fp1= fopen("C:\\Users\\Huawei\\CLionProjects\\ex1.4\\input.txt","r");  //open file
    fp2= fopen("output.txt","w");
    if (fp1==NULL){                                  //control if correct open
        printf("input file not found\n");
        exit(1);
    }
    else if (fp2==NULL){
        printf("error opening output file\n");
        exit(1);
    }
    else {
        while (!feof(fp1)){                      //until file not end
            fgets(line,100, fp1);     //copy line between file
            fprintf(fp2,"%s",line);}
    }
    fclose(fp1);   //file close
    fclose(fp2);
    return 0;
}
