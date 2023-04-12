// CS2211b 2023
// Assignment 04
// Hayden Wies
// 251147012
// hwies
// 2023-03-15


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "headers.h"


para para_ini(void) {
    para p;
    p = (para) malloc(sizeof(para_struct));
    p->lp = NULL;
    p->size=0;
    return p;
}

void para_free(para p) {
    int i;
    for (i=0; i<p->size; i++) {
        line_free(p->lp[i]);
    }
    free(p); 
}

void para_add(para p, line l) {
    int n = p->size + 1;
    // Initialize memory if pointer is NULL
    if (p->lp == NULL) p->lp = (line*) malloc(sizeof(line));
    // Expand memory if already allocated
    else p->lp = (line*) realloc(p->lp, sizeof(line) * n);
    // Set new memory space to line
    p->lp[p->size] = l;
    // Increase size
    p->size = n;
}

void para_print(para p) {
    if (p->lp == NULL) printf("PARAGRAPH IS NULL");
    else {
        // Loop through all lines in paragraph and print
        for (int i = 0; i < p->size; i++) {
            line_print(p->lp[i]);
            printf("\n");
        }
    }
}

// ----- MY METHODS ----- //

int para_search_print(para p, char* c) {
    if (p->lp == NULL) printf("PARAGRAPH IS NULL");
    else {
        int found_word = 0;
        for (int i = 0; i < p->size; i++) {
            // Loop through lines and search for words
            int *n = line_search(p->lp[i], c);
            for (int j = 1; j <= n[0]; j++) {
                // Loop through array *n and print index of each occurrance
                found_word = 1;
                printf("LINE: %d WORD: %d\n", (i + 1), n[j]);
            }
        }

        // Notify user if word does not exist
        if (found_word == 0) {
            printf("That word does not exist in the paragraph you typed.\n");
        }
    }
    return 0;
}