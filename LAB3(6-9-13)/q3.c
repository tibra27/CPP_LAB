#include <stdio.h>
#include <error.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc == 1) {
        puts("File Argument Missing");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("File Not Found");
        exit(EXIT_FAILURE);
    }
    return 0;
}
