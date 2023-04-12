#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


float get_num(void), sim_exp(void), sim_sub_exp(float), md_exp(void), md_sub_exp(float);
char get_op(void);


int main(void) {
    char cont = 'Y';

    while (cont == 'Y' || cont == 'y') {
        // Ask user for a simple expression
        printf("Enter a simple expression you wish to have evaluated:\n");
        // Calculate
        float r = sim_exp();
        printf("Your answer is: %f\n", r);
        printf("Would you like to calculate another expression? (Y/N)\n");
        cont = getchar();
        fflush(stdin);
    }

    return 0;
}


// Input: none, read from stdin
// Effect: get the next operator of the expression
//         this operator can be +, -, *, /, or ’\n’
//         ’\n’ indicates the end of the expression input
//         leading spaces should skipped
// Output: return the next operator of the expression.
char get_op(void) {
    char c = getchar();

    // Pass over ' ' (ascii 32)
    while (c == 32) {
        c = getchar();
    }

    if (c != 10 && c != 42 && c != 43 && c != 45 && c != 47) {
        printf("Invalid symbol found in get_op.");
        exit(EXIT_FAILURE);
    }

    return c;
}


// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num(void) {
    char c = getchar(); 

    char char_num[20];
    int i = 0;
    
    // Pass over ' ' (ascii 32)
    while (c == 32) {
        c = getchar();
    }

    // If character is '-' (ascii 45), '.' (ascii 46) or '0'-'9' (ascii 48-57) add it to string
    bool entry = false;
    while (c >= 45 && c <= 57 && c != 47) {
        // Break loop if c == '-' part way through the reading process (this indicates '-' is the next opperator)
        if (entry == true && c == 45) {
            break;
        } else {
            char_num[i++] = c;
            entry = true;
            c = getchar();
        }
    }

    if (entry == false) {
        // Means no number was ever read because character that didn't meet above conditions was encountered
        printf("Invalid symbol found in get_num.");
        exit(EXIT_FAILURE);
    }

    // Push last character back to stdin (this is the next opperator or a space)
    ungetc(c, stdin);

    // Convert char string to workable number
    double num = atof(char_num);
    return (float) num;
}


// Input: ’sub_exp’: the value of the current sub sim_expression
//                   to the left of the next operator, ’next_op’,
//                   located at the beginning of current stdin.
//                   ’next_op’: an operator, ’+’ or ’-’.  ’next_op’
//                              could also be ’\n’ indicating the end
//                              of the sim_expression.
//                   the rest of the sim_expression will be read in
//                   from stdin
// Effect: the sim_expression is evaluated using recursion:
//         get ’next_op’ with get_op()
//         if ’next_op’ is ’\n’
//             push back ’next_op’ to stdin
//             return ’sub_exp’
//         else (’next_op’ is ’+’ or ’-’)
//             get 'next_md_exp' with md_exp
//             use 'sub_exp next_op next_md_exp' to do recursive call
//             i.e. call sim_sub_exp()
//         end if
// Output: this function returns the value of the current sim_expression
float sim_sub_exp(float sub_exp) {
    char next_op = get_op();
    if (next_op == 10) {
        // \n
        return sub_exp;
    } else {
        float next_num = md_exp();
        if (next_op == 43) {
            // +
            float next_sub_exp = sub_exp + next_num;
            return sim_sub_exp(next_sub_exp);
        } else if (next_op == 45) {
            // -
            float next_sub_exp = sub_exp - next_num;
            return sim_sub_exp(next_sub_exp);
        } else {
            printf("Invalid symbol found in sim_sub_exp.");
            exit(EXIT_FAILURE);
        }
    }
}


// Input: none, the sim_expression will be read in from stdin
// Effect: the next sim_expression is evaluated using
//         a function call.
// Output: this function returns the value of the next sim_expression
float sim_exp(void) {
    float m = md_exp();
    return sim_sub_exp(m);
}


// Input: ’sub_exp’: the value of the current sub md_expression
//                   to the left of the next operator, ’next_op’,
//                   located at the front of current stdin.
//                   ’next_op’: an operator, ’*’ or ’/’.  ’next_op’
//                              could also be ’+’, ’-’, or ’\n’
//                              indicating the end of the md_expression.
//                   the rest of the md_expression will be read in
//                   from stdin
// Effect: the md_expression is evaluated using recursion:
//         get 'next_op' with get_op()
//         if 'next_op' is '+', '-' or '\n'
//             push back 'next_op' to stdin
//             return 'sub_exp'
//         else ('next_op' is '*' or '/')
//             get 'next_num' with get_num()
//             use 'sub_exp next_op next_num' to do recursive call
//             i.e. call md_sub_exp()
//         end if
// Output: this function returns the value of the current md_expression
float md_sub_exp(float sub_exp) {
    char next_op = get_op();
    if (next_op == 10 || next_op == 43 || next_op == 45) {
        // \n, + or -
        ungetc(next_op, stdin);
        return sub_exp;
    } else {
        float next_num = get_num();
        if (next_op == 42) {
            // '*'
            float next_sub_exp = sub_exp * next_num;
            return md_sub_exp(next_sub_exp);
        } else if (next_op == 47) {
            // '/'
            float next_sub_exp = sub_exp / next_num;
            return md_sub_exp(next_sub_exp);
        } else {
            printf("Invalid symbol found in md_sub_exp.");
            exit(EXIT_FAILURE);
        }

    }
}


// Input: none, the md_expression will be read in from stdin
// Effect: the next md_expression is evaluated using
//         a function call.
// Output: this function returns the value of the next md_expression
float md_exp(void) {
    float m = get_num();
    return md_sub_exp(m);
}