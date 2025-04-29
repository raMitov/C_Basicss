#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Usage: %s source.txt dest.txt\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if(!in) { perror("fopen source"); return 1;}
    FILE *out = fopen(argv[2], "w");
    if(!out) {perror("fopen dest"); return 1;}

    int c;
    while((c = fgetc(in)) != EOF){
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
    printf("copy complete\n");
}