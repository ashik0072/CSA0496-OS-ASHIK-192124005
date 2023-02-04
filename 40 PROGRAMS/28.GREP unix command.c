#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [string to search] [file name]\n", argv[0]);
        exit(1);
    }

    char *search_string = argv[1];
    char *file_name = argv[2];

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[1000];
    int line_number = 1;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_string) != NULL) {
            printf("Line %d: %s", line_number, line);
        }
        line_number++;
    }

    fclose(fp);
    return 0;
}
