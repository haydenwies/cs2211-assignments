// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


#include "headers.h"
#include <stdlib.h>
#include <stdio.h>


BStree bstree_ini(void) {
    // Create empty bstree obj and allocate memory
    BStree t;
    t = (BStree_node*) malloc(sizeof(BStree_node));
    t->data = NULL;
    t->key = NULL;
    t->left = NULL;
    t->right = NULL;
    return t;
};

void bstree_insert(BStree bst, Key key, Data data) {
    if (bst->data == NULL) {
        // Leaf node
        // Set values and add new leaves
        bst->key = key;
        bst->data = data;
        bst->left = bstree_ini();
        bst->right = bstree_ini();
    }  else {
        int cmp = key_comp(bst->key, key);
        if (cmp < 0) {
            // Node is larger than key, traverse right
            bstree_insert(bst->right, key, data);
        } else if (cmp > 0) {
            // Node is less than key, traverse left
            bstree_insert(bst->left, key, data);
        } else {
            // Node exists in current place, update data
            bst->data = data;
        }
    }
};

Data bstree_search(BStree bst, Key key) {
    if (bst->data == NULL) {
        return NULL;
    } else {
        int cmp = key_comp(bst->key, key);
        if (cmp < 0) {
            // Node is larger than key, traverse right
            return bstree_search(bst->right, key);
        } else if (cmp > 0) {
            // Node is less than key, traverse left
            return bstree_search(bst->left, key);
        } else {
            // Node and key match
            return bst->data;
        }

        return NULL;
    }
};

void bstree_traverse(BStree bst) {
    if (bst->data == NULL) {
        // Leaf node
        return;
    } else {
        // First call on left child
        bstree_traverse(bst->left);

        // Then print data
        printf("String 1: %s\n", bst->key->str1);
        printf("String 2: %s\n", bst->key->str2);
        printf("Occurrences: %d\n", *bst->data);
        printf("----------\n");

        // Finlly call on right child
        bstree_traverse(bst->right);
    }
};

void bstree_free(BStree bst) {
    if (bst->data == NULL) {
        // Leaf node, deallocate
        data_free(bst->data);
        key_free(bst->key);
        free(bst);
    } else {
        // If not leaf, traverse left and right first
        bstree_free(bst->left);
        bstree_free(bst->right);

        // Then free data and node
        data_free(bst->data);
        key_free(bst->key);
        free(bst);
    }
};