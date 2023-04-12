// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


#include "headers.h"
#include <stdio.h>


Matrix matrix_construction(void) {
    // Create new bstree
    Matrix m = bstree_ini();
    return m;
};

unsigned char matrix_index_in(Matrix m, Index index1, Index index2) {
    // Create key from provided indexes
    Key k = key_ini();
    key_set(k, index1, index2);

    // Search bstree to see if data exists for this key
    Data d = bstree_search(m, k);
    if (d == NULL) {
        // If data doesn't exist return 0
        return 0;
    } else {
        // If data exists return 1
        return 1;
    }
};

Value matrix_get(Matrix m, Index index1, Index index2) {
    // Create key from provided indexes
    Key k = key_ini();
    key_set(k, index1, index2);
    
    // Search bstree for data matching key
    Data d = bstree_search(m, k);
    if (d == NULL) {
        // Return null if node doesn't exist
        return -1;
    } else {
        // Otherwise return data
        return *d;
    }
};

void matrix_set(Matrix m, Index index1, Index index2, Value value) {
    // Create key and data obj
    Key k = key_ini();
    Data d = data_ini();
    key_set(k, index1, index2);
    data_set(d, value);

    // Insert in bstree obj
    bstree_insert(m, k, d);
};

void matrix_list(Matrix m) {
    bstree_traverse(m);
};

void matrix_destruction(Matrix m) {
    bstree_free(m);
};