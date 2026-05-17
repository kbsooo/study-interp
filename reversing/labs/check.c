
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) return 1;

    if (strcmp(argv[1], "secret") == 0) {
        puts("correct");
    } else {
        puts("wrong");
    }

    return 0;
}
