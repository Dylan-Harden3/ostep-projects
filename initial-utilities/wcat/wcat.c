#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv) {
    if (argc == 0) {
        return 0;
    }
    for (int i=1; i < argc; i++) {
        FILE* f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }
        char buffer[8192];
        while(fgets(buffer, sizeof(buffer), f) != NULL) {
            printf("%s", buffer);
        }
    }
    return 0;
}