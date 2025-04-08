#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
void readAllSymbolsFromFile(const char* fileName) {
    FILE * filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", fileName, strerror(errno));
        return;
    }
    int count = 0;
    int ch;
    while ((ch = getc(filePointer)) != EOF) {
        count++;
    }
    fclose(filePointer);
    printf("Number of symbols read: %d\n", count);
}
void readAllNonEmplySymbolsFromFile(const char* fileName) {
    FILE * filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", fileName, strerror(errno));
        return;
    }
    int count = 0;
    int ch;
    while ((ch = getc(filePointer)) != EOF) {
        if (ch >= 32 && ch <= 126) {
            count++;
        }
    }
    fclose(filePointer);
    printf("Number of symbols read: %d\n", count);
}
void countWordsFromFile(const char* fileName) {
    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", fileName, strerror(errno));
        return;
    }

    int count = 0;
    int inWord = 0;
    int ch;

    while ((ch = getc(filePointer)) != EOF) {
        if (isspace(ch)) {
            if (inWord) {
                count++;
                inWord = 0;
            }
        }
        else {
            inWord = 1;
        }
    }
    if (inWord) {
        count++;
    }

    fclose(filePointer);
    printf("Word count: %d\n", count);
}
void countLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", filename, strerror(errno));
        return;
    }


    int lines = 0;
    int ch;
    int last_char = EOF;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
        last_char = ch;
    }
    if (last_char != EOF && last_char != '\n') {
        lines++;
    }

    fclose(file);
    printf("%d\n", lines);
}
void countNonEmptyLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Грешка при отваряне на файл");
        return;
    }

    int ch;
    int has_content = 0;
    int line_count = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            if (has_content) {
                line_count++;
                has_content = 0;
            }
        } else if (!isspace((unsigned char)ch)) {
            has_content = 1;
        }
    }

    if (has_content) {
        line_count++;
    }

    fclose(file);
    printf("%d\n", line_count);
}
int main(void) {
    char input[10];
    printf("Please enter a command: ");
    scanf("%s", input);
    printf("Command: %s\n", input);
    char file[100];
    printf("Please enter a file name: ");
    scanf("%s", file);
    printf("File name: %s\n", file);
        switch (input[1]) {
            case 'c': readAllSymbolsFromFile(file); break;
            case 'C': readAllNonEmplySymbolsFromFile(file); break;
            case 'w': countWordsFromFile(file); break;
            case 'l': countLines(file); break;
            case 'L': countNonEmptyLines(file); break;
            case 's': readAllSymbolsFromFile(file), readAllSymbolsFromFile(file), countWordsFromFile(file), countLines(file), countNonEmptyLines(file); break;
            case 'h':
                printf("-c for reading all symbols from file\n -C for reading all non empy symbols from file\n -w for counting words from file\n -l for counting all lines\n -L for reading all non empty lines\n -s for everything\n"); break;
            default : return 0;
        }


}