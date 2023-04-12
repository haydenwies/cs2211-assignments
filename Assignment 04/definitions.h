// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


typedef int *Data;
typedef struct {
    char *str1; 
    char *str2;
} Key_struct;
typedef Key_struct* Key;

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node* BStree;

typedef char* Index;
typedef int Value;
typedef BStree Matrix;