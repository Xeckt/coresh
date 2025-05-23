#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void start_coresh() {
    fflush(stdout);
    printf("coresh> ");
}

/*
 * This function is probably inefficient, but frankly not too bothered about it.
 * I probably should realloc the buffer if it's smaller than the original bufsize
 * but for now it does what is intended.
 * P.S. - I know getline() exists.
 */
char *read_line(void) {
    int bufsize = 1024;
    char *buffer = malloc(sizeof(char) * bufsize);

    if (!buffer) {
        fprintf(stderr, "failed to allocate memory for read_line\n");
        exit(EXIT_FAILURE);
    }

    size_t position = 0;

    for (int c; (c = getchar()) != EOF && c != '\n';) {
        buffer[position++] = c;
        if (position >= bufsize - 1) {
            int buffer_size = bufsize;
            buffer_size += bufsize;

            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                fprintf(stderr, "failed to re-allocate memory for read_line\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    buffer[position] = '\0';

    if (trace_mode) {
        for (size_t i = 0; buffer[i] != '\0'; i++) {
            printf("Char %zu: '%c' (ASCII %d)\n", i, buffer[i], buffer[i]);
        }
    }

    return buffer;
}