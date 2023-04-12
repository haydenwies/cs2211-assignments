#include <stdio.h>


double calc(double, int);

int main(void) {
    double base, result;
    int exp;

    // Prompt user for base and exponent
    printf("Enter base of calculation: ");
    scanf(" %lf", &base);
    printf("Enter exponent of calculation: ");
    scanf(" %d", &exp);

    // Run calculation with absolute value of exponent
    if (exp < 0) {
        result = calc(base, (exp*-1));
    } else {
        result = calc(base, exp);
    }
    

    if (exp > 0) {
        // If exponent is positive return result
        printf("Your answer is: %.10lf\n\n", result);
    } else {
        // If exponent is negaitve return 1/result
        printf("Your answer is: %.10lf\n\n", 1/result);
    }

    main();
}
    

double calc(double base, int exp) {
    // Invoke recursion to run calculation
    if (exp==0) {
        return 1;
    }  else if ((exp&1) == 0) {
        return calc(base*base, exp/2);
    } else {
        return base * calc(base*base, exp/2);
    }
}