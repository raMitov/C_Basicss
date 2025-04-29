#include <stdio.h>
#include <stdlib.h>

typedef struct Record{
    int id;
    char name[20];
}Record;

int main(int argc, char* argv[]){
    if(argc != 2) {fprintf(stderr, "No arguments %s", argv[0]); return 1;}
    FILE *binptr = fopen(argv[1], "rb");
    if(!binptr) {perror("Couldnt open file"); return 1;}
    fseek(binptr, 0, SEEK_END);      // Move to end of file
    long size = ftell(binptr);       // Get current offset = file size
    rewind(binptr);
    int n = size/sizeof(Record);
    Record *buf = malloc(n * sizeof *buf);

    fread(buf, sizeof(Record), n,binptr );
    for(int i = 0; i < n; i++){
        printf("ID=%d Name=%s\n", buf[i].id, buf[i].name);
    }
    fclose(binptr);
}