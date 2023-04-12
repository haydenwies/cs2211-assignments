// CS2211b 2023
// Assignment 04
// Hayden Wies
// 251147012
// hwies
// 2023-03-15


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "headers.h"


word word_ini(void) {
    word w;
    w = (word) malloc(sizeof(word_struct));
    w->cp = NULL;
    w->size = 0;
    return w;
}

void word_free(word wd) {
    if (wd->cp != NULL) free(wd->cp);
    free(wd);
}

void word_print(word w) {
    if (w->cp == NULL) printf("WORD IS EMPTY");
    // Loop through each char and print
    for (int i = 0; i < w->size; i++) {
        printf("%c", w->cp[i]);
    }
}

// ----- MY METHODS ----- //

void word_char_add(word w, char c) {
    int n = w->size + 1;
    // Initialize memory if pointer is NULL
    if (w->cp == NULL) w->cp = (char*) malloc(sizeof(char));
    // Expand memory if already allocated
    else w->cp = (char*) realloc(w->cp, sizeof(char) * n);
    // Set new memory space to char
    w->cp[w->size] = c;
    // Increase size
    w->size = n;
}

int word_cmp(word w1, char* w2) {
    // Compare word to w2
    if (strcmp(w1->cp, w2)) {
        return 0;
    } else {
        return 1;
    }
}