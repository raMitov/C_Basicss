#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);
    std::cout << "Now enter " << n - 1 << "files you want to read from and " << 1 << " file to have the other file's data." << std::endl;
    char * files[n];
    for (int i = 0; i < n; i++) {
        printf("Enter filename: ");
        char filename[100];
        scanf("%s", filename);
        files[i] = new char[strlen(filename) + 1];
        strcpy(files[i], filename);
        printf("%s\n", filename);
    }
    FILE * outputFile = fopen(files[n-1], "w");
    if (outputFile == NULL) {
        perror("Cannot open output file");
        return 1;
    }
    int numberOfFiles = n-1;
    int ch;
    for (int i = 0; i < numberOfFiles; i++) {

        FILE * file = fopen(files[i], "r");
        if (file == NULL) {
            fprintf(stderr, "Cannot open input file: %s\n", files[i]);
            continue;
        }
        while ((ch = fgetc(file)) != EOF) {
            fputc(ch, outputFile);
        }
        fputc('\n', outputFile);
        fclose(file);
    }
    for (int i = 0; i < n; i++) {
        delete[] files[i];
    }
    fclose(outputFile);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.