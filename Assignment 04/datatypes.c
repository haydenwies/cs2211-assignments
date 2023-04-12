// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


#include "headers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Data data_ini() {
    // Create empty data obj and allocate memory
    Data d;
    d = (Data) malloc(sizeof(Data));
    return d;
};

void data_set(Data data, int intdata) {
    // Set value of data pointer equal to int
    *data = intdata;
};

void data_free(Data data) {
    // De-allocate memory
    free(data);
};

Key key_ini() {
    // Create empty key obj and allocate memory
    Key k;
    k = (Key_struct*) malloc(sizeof(Key_struct));
    k->str1 = NULL;
    k->str2 = NULL;

    return k;
};

void key_set(Key key, char *str1, char *str2) {
    // Duplicate strings into key values
    key->str1 = string_dup(str1);
    key->str2 = string_dup(str2);
};

int key_comp(Key key1, Key key2) {
    // First compare key1, if equal, compare key2
    int val = strcmp(key1->str1, key2->str1);
    if (val == 0) {
        val = strcmp(key1->str2, key2->str2);
    }

    return val;
};

void key_free(Key key) {
    // De-allocate memory
    free(key);
};

char *string_dup(char *str) {
    // Allocate new memory size of str
    char* new_str = (char*) malloc(sizeof(char)*strlen(str));
    // Copy each char to new_str
    for (int i = 0; i < strlen(str); i++) {
        new_str[i] = str[i];
    }

    return new_str;
};