#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ccwc.h"

// -c output number of bytes
// -l number of lines
// -w number of words 
// -m number of characters
// no flag will output all 
int main(int argc, char *argv[]) {
    FILE *file;
    char *flag = NULL, *filename = NULL;

    if (argc == 3) {
        flag = argv[1];
        filename = argv[2];
        file = fopen(filename, "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }

        if (strcmp(flag, "-c") == 0) {
            printf("%u %s\n", numberOfBytes(file), filename);
        } else if (strcmp(flag, "-l") == 0) {
            printf("%d %s\n", numberOfLines(file), filename);
        } else if (strcmp(flag, "-w") == 0) {
            printf("%d %s\n", numberOfWords(file), filename);
        } else if (strcmp(flag, "-m") == 0) {
            printf("%d %s\n", numberOfChars(file), filename);
        }

        fclose(file);

    } else if (argc == 2) {
        if (argv[1][0] == '-') {
            flag = argv[1];
            file = stdin; // Read from stdin

            if (strcmp(flag, "-c") == 0) {
                printf("%u\n", numberOfBytes(file));
            } else if (strcmp(flag, "-l") == 0) {
                printf("%d\n", numberOfLines(file));
            } else if (strcmp(flag, "-w") == 0) {
                printf("%d\n", numberOfWords(file));
            } else if (strcmp(flag, "-m") == 0) {
                printf("%d\n", numberOfChars(file));
            }

        } else {
            filename = argv[1];
            file = fopen(filename, "r");
            if (!file) {
                perror("Error opening file");
                return 1;
            }

            printf("%d ", numberOfLines(file));
            printf("%d ", numberOfWords(file));
            printf("%u ", numberOfBytes(file));
            printf("%s\n", filename);

            fclose(file);
        }

    } else if (argc == 1) {
        // Reading from stdin if no arguments are provided
        file = stdin;

        printf("%d ", numberOfLines(file));
        printf("%d ", numberOfWords(file));
        printf("%u ", numberOfBytes(file));
    } else {
        fprintf(stderr, "Usage: %s [-c|-l|-w|-m] <filename>\n", argv[0]);
        return 1;
    }

    return 0;
}
