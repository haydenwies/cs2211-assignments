// CS2211b 2023
// Assignment 04
// Hayden Wies
// 251147012
// hwies
// 2023-03-15


#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


void prompt_line(para), parse_line(para), prompt_word(para), parse_word(para);


int main(void) {
    // Create paragraph object
    para p = para_ini();

    // Prompt user for lines of text
    prompt_line(p);
    // After recieving all lines, print back to user
    para_print(p);
    printf("\n");

    // Prompt user for words to find in paragraph
    prompt_word(p);
     
    return 0; 
}

void prompt_line(para p) {
    // Print message
    printf("Enter a line of text or press 'enter' to continue the program.\n");
    // Check if first character is LF
    char c = getchar();
    if (c == 10) {
        // User hit enter without typing a character
        // End program
        return;
    } else {
        // New line found
        // Push character back on stdin
        ungetc(c, stdin);
        // Parse line
        parse_line(p);
        // Call prompt again
        prompt_line(p);
    }
}

void parse_line(para p) {
    line l = line_ini();
    word w = NULL;
    char c = getchar();
    
    // LF (ascii 10)
    while (c != 10) {
        // ' ' (ascii 32)
        if (c != 32) {
            
            if (w == NULL) {
                // Create new w
                w = word_ini();
            }
            
            // Add c to w
            word_char_add(w, c);

            // Check next char
            char next_c = getchar();

            // Check if next char is a ' ' or LF
            if (next_c == 32 || next_c == 10) {
                // Add w to line
                line_add(l, w);
                // Set w to null
                w = NULL;
            }

            // Put char back on stdin
            ungetc(next_c, stdin);
        }
        c = getchar();
    }    

    para_add(p, l);
}

void prompt_word(para p) {
    // Print message
    printf("Enter a word you would like to search for or press 'enter' to end the program.\n");
    // Check first character is LF
    char c = getchar();
    if (c == 10) {
        // User hit enter without typing a character
        // End program
        return;
    } else {
        // New line found
        // Push character back on stdin
        ungetc(c, stdin);
        // Parse word
        parse_word(p);
        // Call prompt again
        prompt_word(p);
    }
}

void parse_word(para p) {
    char word[40] = {};

    // Get word from stdin and save in word
    int i = 0;
    char c = getchar();
    while (c != 32 && c != 10) {
        word[i++] = c;
        c = getchar();
    }

    // Search for word and print results
    para_search_print(p, word);
    printf("\n");

}