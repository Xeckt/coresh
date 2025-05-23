#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char *read_input(void) {
    int bufsize = 5;
    char *buffer = malloc(sizeof(char) * bufsize);

    if (!buffer) {
        fprintf(stderr, "failed to allocate memory for read_line\n");
        exit(EXIT_FAILURE);
    }

    size_t position = 0;

    for (int c; (c = getchar()) != EOF && c != '\n';) {
        if (position >= bufsize - 1) {
            bufsize += 8; // Grow in minimal increments so we don't reallocate too much memory
            char *n_buffer = realloc(buffer, bufsize);
            if (!n_buffer) {
                free(buffer);
                fprintf(stderr, "failed to re-allocate memory for read_line\n");
                exit(EXIT_FAILURE);
            }
            buffer = n_buffer;
        }
        buffer[position++] = (char)c;
    }

    buffer[position] = '\0';

    /*for (size_t i = 0; buffer[i] != '\0'; i++) {
        printf("Char %zu: '%c' (ASCII %d)\n", i, buffer[i], buffer[i]);
    }*/

    return buffer;
}