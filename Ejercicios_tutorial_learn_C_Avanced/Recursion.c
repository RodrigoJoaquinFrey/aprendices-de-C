#include <stdio.h>

/*
unsigned int multiply(unsigned int x, unsigned int y){
    if (x == 1){
        // Terminating case 
        return y;
    }
    else if (x > 1){
        // Recursive step 
        return y + multiply(x-1, y);
    }

    // Catch scenario when x is zero 
    return 0;
}

int main() {
    printf("3 times 5 is %d", multiply(3, 5));
    return 0;
}*/

int factorial(int number);

    int main() {
        /* testing code */
        printf("0! = %i\n", factorial(0));
        printf("1! = %i\n", factorial(1));
        printf("3! = %i\n", factorial(3));
        printf("5! = %i\n", factorial(5));
    }

    int factorial(int number) {
        if (number > 1) {
            return number * factorial(number-1);
        }
        else {
	           return 1;
        }
    }