// CS2211b 2023
// Assignment 05
// Hayden Wies
// 251147012
// hwies
// 2023-04-01


Data data_ini(void);
void data_set(Data data, int intdata);
void data_free(Data data);

Key key_ini(void);
void key_set(Key key, char *str1, char *str2);
int key_comp(Key key1, Key key2);
void key_free(Key key);

char *string_dup(char *str);