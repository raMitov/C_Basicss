#include <stdio.h>
#include <stdlib.h>
typedef struct Record{
    int id;
    char Name[20];
}Record;

int main(int argc, char* argv[]){
    if(argc != 2) {fprintf(stderr, "No arguments %s", argv[0]); return 1;}
    Record rec = {810, "Radoslav Mitov"};
    Record rec2 = {3010, "Stanislava Yord."};

    FILE *binptr = fopen(argv[1], "ab");
    if(!binptr) {perror("Couldnt open file"); return 1;}
    fwrite(&rec, sizeof(Record), 1, binptr);
    fwrite(&rec2, sizeof(Record), 1, binptr);

    fclose(binptr);
    printf("Transfered Successfuly");

}