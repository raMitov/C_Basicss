#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *fp = fopen("Hangman.txt", "r");
    int count = 5;
    printf("You are playing hangman and you have 5 tries to guess the word\n");
    int letterCount = 0;
    int ch;
    int size = 2;
    char * letters =(char*)malloc(size * sizeof(char));
    while ((ch = fgetc(fp)) != EOF) {
        letters[letterCount] = (char)ch;
        letterCount++;
        if (letterCount >= size) {
            letters = (char*)realloc(letters, size * sizeof(char));
        }
    }
    printf("\n");
    for (int i = 0; i < letterCount; i++) {
        if (i == 0) {
            printf("%c", letters[i]);
        }
        else {
            printf("_");
        }
    }
    char c;
    printf("\n");
    printf("You have a %d letter word\n", letterCount);
    int correct = 0;
    int lettercorrect[letterCount];
    for (int i = 0; i < letterCount; i++) {
        lettercorrect[i] = 0;
    }
    for (int i = count; i >= 0; i--) {
        printf("You have %d tries.\n Enter a letter : ", i);
        scanf(" %c", &c);
        for (int j = 0; j < letterCount; j++) {

            if (c == letters[j]) {
                printf("%c", c);
                lettercorrect[j] = 1;
            }
            else {
                printf("_");
            }
        }
        printf("\n");
        int letterbool = 0;
        for (int j = 1; j < letterCount; j++) {
            if (lettercorrect[j] == 1) {
                letterbool++;
            }
        }
        if (letterbool == letterCount - 1) {
            printf("you won!");
            break;
        }
    }


    free(letters);



}