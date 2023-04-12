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


line line_ini(void) {
    line l;
    l = (line) malloc(sizeof(line_struct));
    l->wp = NULL;
    l->size = 0;
    return l;
}

void line_free(line l) {
    int i;
    for (i=0; i<l->size; i++) {
        word_free(l->wp[i]);
    }
    free(l); 
}

void line_add(line l, word w) {
    int n = l->size + 1;
    // Initialize memory if pointer is NULL
    if (l->wp == NULL) l->wp = (word*) malloc(sizeof(word));
    // Expand memory if already allocated
    else l->wp = (word*) realloc(l->wp, sizeof(word) * n);
    // Set new memory space to word
    l->wp[l->size] = w;
    // Increase size
    l->size = n;
}

void line_print(line l) {
    if (l->wp == NULL) printf("LINE IS EMPTY");
    else {
        // Loop through each word in line and print
        for (int i = 0; i < l->size; i++) {
            word_print(l->wp[i]);
            // Print space if not last word
            if (i != l->size - 1) printf("%c", ' ');
        }
    }
}

// ----- MY METHODS ----- //

int *line_search(line l, char* w) {
    // Create list to store all indexes where word appears in line
    int *posn_list = (int*) malloc(sizeof(int));
    // Position 0 of list contains count of how many occurrances there are
    posn_list[0] = 0;

    if (l->wp == NULL) printf("LINE IS EMPTY");
    else {
        // Loop through all words
        for (int i = 0; i < l->size; i++) {
            if (word_cmp(l->wp[i], w)) {
                // If words match
                // Increment indx
                posn_list[0]++;
                // Resize posn_list
                posn_list = (int*) realloc(posn_list, sizeof(int) * (posn_list[0] + 1));
                // Add i to posn_list
                posn_list[posn_list[0]] = (i + 1);
            }
        }
    }

    return posn_list;
}