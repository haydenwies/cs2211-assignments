// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


#include "headers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void parse_input(Matrix), parse_line(Matrix), display_occurrences(Matrix);


int main(void) {
    Matrix m = matrix_construction();

    // Prompt user for input
    printf("Enter lines of text, each consisiting of two words. Press enter on an empty line when done.\n");
    parse_input(m);

    display_occurrences(m);

    matrix_destruction(m);

    return 0;
};

void parse_input(Matrix m) {
    char c = getchar();

    while (c != 10) {
        // Put back borrowed character
        ungetc(c, stdin);
        // Parse current line
        parse_line(m);
        // Get next char after parsing line to see if input continues
        c = getchar();
    }
};

void parse_line(Matrix m) {
    int word_count = 0;
    char s1[50] = "";
    char s2[50] = "";
    char c = getchar();

    while (c != 10) {
        if (c != 32) {

            // Determine which string to add char to
            if (word_count == 0) {
                // Add to s1
                strncat(s1, &c, 1);
            } else if (word_count == 1) {
                // Add to s2
                strncat(s2, &c, 1);
            } else {
                // More than two words in line, exit with error
                printf("ERROR: More than two words found in line.\n");
                exit(EXIT_FAILURE);
            }

            // Check if next char is ' ' or LF
            char next_c = getchar();
            if (next_c == 10 || next_c == 32) {
                word_count++;
            }

            ungetc(next_c, stdin);
        }
        
        c = getchar();
    }

    if (word_count == 1) {
        printf("ERROR: Only one word found in line.\n");
        exit(EXIT_FAILURE);
    }

    if (word_count == 2) {
        // Check if index for s1 and s2 is in matrix
        unsigned int is_in = matrix_index_in(m, s1, s2);
        if (is_in == 1) {
            // If yes store in matrix with value val+1
            int val = matrix_get(m, s1, s2);
            matrix_set(m, s1, s2, val+1);
        } else {
            // If no store in matrix with value 1
            matrix_set(m, s1, s2, 1);
        }
    }
};

void display_occurrences(Matrix m) {
    matrix_list(m);
};