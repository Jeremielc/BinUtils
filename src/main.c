/*
 * main.c
 *
 *  Created on: 24 juin 2016
 *      Author: HRNS9487
 */

#include "headers/header.h"

int main(int argc, char** argv) {
	printf("> ");
	argc = scanf("%s %s %s", argv[0], argv[1], argv[2]);

	if (argc == 3) {
		char* args[2] = { argv[1], argv[2] };

		if (strcmp(argv[0], "bintoascii") == 0) {
			bintoascii(2, args);
		} else if (strcmp(argv[0], "asciitobin") == 0) {
			asciitobin(2, args);
		} else {
			displayHelp();
		}
	} else {
		displayHelp();
	}

	return 0;
}

void displayHelp() {
	printf("displayhelp\n");
}
