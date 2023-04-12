#include <stdio.h>


float cf(void), ci(void), kp(void), mf(void), numPrompt(void);

int main(void) {
    char option;
    float convertedNum;

    printf("Please enter which calculation you would like to compute:\n1: conversion between Celsius and Fahrenheit\n2: conversion between Centimetre and Inch\n3: conversion between Kilogram and Pound\n4: conversion between Meter and Feet\nq/Q: quit\n");
    scanf(" %c", &option);

    switch (option) {
        case '1':
            convertedNum = cf();
            printf("Your converted value is %.2f\n\n", convertedNum);
            main();
            break;
        case '2':
            convertedNum = ci();
            printf("Your converted value is %.2f\n\n", convertedNum);
            main();
            break;
        case '3':
            convertedNum = kp();
            printf("Your converted value is %.2f\n\n", convertedNum);
            main();
            break;
        case '4':
            convertedNum = mf();
            printf("Your converted value is %.2f\n\n", convertedNum);
            main();
            break;
        case 'q':
            break;
        case 'Q':
            break;
        default:
            main();
    }

    return 0;
}

// For calulations between Celsius and Farenheit
float cf() {
    char direction;
    float num, convertedNum;

    printf("Which direction would you like to convert?\nC: conversion from Celsius to Fahrenheit\nF: conversion from Fahrenheit to Celsius\n");
    scanf(" %c", &direction);

    switch (direction) {
        case 'C':
            num = numPrompt();
            convertedNum = ((num * 9/5) + 32);
            break;
        case 'F':
            num = numPrompt();
            convertedNum = ((num - 32) * 5/9);
            break;
        default:
            cf();
    }

    return convertedNum;
}

// For calculations between Centimetres and Inches
float ci() {
    char direction;
    float num, convertedNum;

    printf("Which direction would you like to convert?\nC: conversion from Centimetre to Inch\nI: conversion from Inch to Centimetre\n");
    scanf(" %c", &direction);

    switch (direction) {
        case 'C':
            num = numPrompt();
            convertedNum = (num / 2.54);
            break;
        case 'I':
            num = numPrompt();
            convertedNum = (num * 2.54);
            break;
        default:
            ci();
    }

    return convertedNum;
}

// For calculations between Kilograms and Pounds
float kp() {
    char direction;
    float num, convertedNum;

    printf("Which direction would you like to convert?\nK: conversion from Kilogram to Pound\nP: conversion from Pound to Kilogram\n");
    scanf(" %c", &direction);

    switch (direction) {
        case 'K':
            num = numPrompt();
            convertedNum = (num * 2.20462262185);
            break;
        case 'P':
            num = numPrompt();
            convertedNum = (num / 2.20462262185);
            break;
        default:
            kp();
    }
    
    return convertedNum;
}

// For calculations between Meters and Feet
float mf() {
    char direction;
    float num, convertedNum;

    printf("Which direction would you like to convert?\nM: conversion from Meter to Feet\nF: conversion from Feet to Meter\n");
    scanf(" %c", &direction);

    switch (direction) {
        case 'M':
            num = numPrompt();
            convertedNum = (num * 3.28084);
            break;
        case 'F':
            num = numPrompt();
            convertedNum = (num / 3.28084);
            break;
        default:
            mf();
    }

    return convertedNum;
}

// Prompt to get number user desires to convert
float numPrompt(void) {
    float num;

    printf("Enter the number you would like to convert: ");
    scanf(" %f", &num);

    return num;
}