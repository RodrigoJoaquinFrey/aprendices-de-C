#include <stdio.h>

int main() {

    //numeros pares con while
    int n = 0;
    while (n < 10) {
        n++;

    /* check that n is odd */
    if (n % 2 == 1) {
        /* go back to the start of the while block */
        continue;
    }

    /* we reach this code only if n is even */
    printf("The number %d is even.\n", n);
    }

    //Ejercicio
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i < 10) {
        
        /* your code goes here */
        if (array[i] < 5) {
            i++;
            continue;
        }

        if (array[i] > 10) {

            break;
        }

        printf("%d\n", array[i]);
        i++;
    }


    return 0;
}