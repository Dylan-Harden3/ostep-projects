#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int includes(char* line, char* search_term, int bytes) {
    for(int i=0; i<bytes; i++) {
        if (strncmp(line+i, search_term, strlen(search_term)) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    char* search_term = argv[1];
    char* line = NULL;
    size_t len = 0;
    int read;
    if (argc == 2) {
        read = getline(&line, &len, stdin);
        while (read != -1) {
            if (includes(line, search_term, read)) {
                printf("%s", line);
            }
            read = getline(&line, &len, stdin);
        }
    }
    for (int i=2; i < argc; i++) {
        FILE* f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("wgrep: cannot open file\n");
            return 1;
        }
        read = getline(&line, &len, f);
        while (read != -1) {
            if (includes(line, search_term, read) == 1) {
                printf("%s", line);
            }
            read = getline(&line, &len, f);
        }
    }
    return 0;
}