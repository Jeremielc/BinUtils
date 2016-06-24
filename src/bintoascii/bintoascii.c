/* 
 * File:   main.c
 * Author: Jérémie Leclerc : jeremie.leclerc@fime.com
 *
 * Created on 21 juin 2016, 17:31
 */

#include "../headers/header.h"

int bintoascii(int argc, char** argv) {
    if (argc < 3) {
        perror("No file was specified at the execution.\n");
        printf("You must run the program using 'bintoascci.exe fileToRead fileToWrite'.\n");
        exit(-1);
    }

    FILE* source = fopen(argv[1], "rb");
    FILE* dest = fopen(argv[2], "wt");
    if (source == NULL || dest == NULL) {
        perror("Unable to open the specified file.\n");
        exit(-2);
    }

    fseek(source, 0, SEEK_END);
    long fileLength = ftell(source);
    rewind(source);

    char* buffer = (char*) malloc(fileLength * sizeof ( char));
    fread(buffer, fileLength, 1, source);
    fclose(source);

    register int i = 0;
    while (i < fileLength) {
        switch (buffer[i]) {
            case 0:
                fprintf(dest, "%s", "00 ");
                break;
            case 1:
                fprintf(dest, "%s", "01 ");
                break;
            case 2:
                fprintf(dest, "%s", "02 ");
                break;
            case 3:
                fprintf(dest, "%s", "03 ");
                break;
            case 4:
                fprintf(dest, "%s", "04 ");
                break;
            case 5:
                fprintf(dest, "%s", "05 ");
                break;
            case 6:
                fprintf(dest, "%s", "06 ");
                break;
            case 7:
                fprintf(dest, "%s", "07 ");
                break;
            case 8:
                fprintf(dest, "%s", "08 ");
                break;
            case 9:
                fprintf(dest, "%s", "09 ");
                break;
            case 10:
                fprintf(dest, "%s", "0A ");
                break;
            case 11:
                fprintf(dest, "%s", "0B ");
                break;
            case 12:
                fprintf(dest, "%s", "0C ");
                break;
            case 13:
                fprintf(dest, "%s", "0D ");
                break;
            case 14:
                fprintf(dest, "%s", "0E ");
                break;
            case 15:
                fprintf(dest, "%s", "0F ");
                break;
            default:
                fprintf(dest, "%hhX ", buffer[i]);
                break;
        }
        i++;
        
        if (i % 16 == 0) {
            fprintf(dest, "%c", '\n');
        }
    }

    free(buffer);
    fclose(dest);
    
    return (EXIT_SUCCESS);
}

