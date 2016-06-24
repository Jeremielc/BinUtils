/* 
 * File:   main.c
 * Author: Jérémie Leclerc : jeremie.leclerc@fime.com
 *
 * Created on 21 juin 2016, 17:31
 */

#include "../headers/header.h"

int asciitobin(int argc, char** argv) {
    if (argc < 3) {
        perror("No file was specified at the execution.\n");
        printf("You must run the program using 'asciitobin.exe fileToRead fileToWrite'.\n");
        exit(-1);
    }

    FILE* source = fopen(argv[1], "rt");
    FILE* dest = fopen(argv[2], "wb");
    if (source == NULL || dest == NULL) {
        perror("Unable to open the specified file.\n");
        exit(-2);
    }

    char* line = (char*) calloc(49, sizeof(char));
    int lineNumber = 0;
    
    while (!feof(source)) { //line counter
        fgets(line, 48, source);
        lineNumber += 1;
    }
    
    rewind(source);
    char* string = (char*) calloc(lineNumber * 49, sizeof(char));
    
    while (!feof(source)) {
        fgets(line, 48, source);
        string = strcat(string, line);
    }
    
    free(line); //To reuse it
    line = (char*) calloc(lineNumber * strlen(string), sizeof(char));
    
    for (register int i = 0, pos = 0; i < strlen(string); i += 1) { //On retire les espaces et les retours à la ligne.
        if (string[i] != ' ' && string[i] != '\n') {
            line[pos] = string[i];
            pos += 1;
        }
    }
    
    char temp[3];
    for (register int i = 0; i < strlen(line); i += 2) {
        temp[0] = line[i];
        temp[1] = line[i + 1];
        temp[2] = '\0';
        
        unsigned char converted = strtol(temp, NULL, 16);
        fwrite(&converted, 1, 1, dest);
    }

    fclose(source);
    fclose(dest);
    free(string);
    free(line);
    
    return (EXIT_SUCCESS);
}

