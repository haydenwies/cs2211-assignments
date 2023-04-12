// CS2211b 2023
// Assignment 04
// Hayden Wies
// 251147012
// hwies
// 2023-03-15


typedef struct {
    char *cp;
    int size;
} word_struct;
typedef word_struct* word;

typedef struct {
    word *wp;
    int size;
} line_struct;
typedef line_struct* line;

typedef struct {
    line *lp;
    int size;
} para_struct;
typedef para_struct* para;