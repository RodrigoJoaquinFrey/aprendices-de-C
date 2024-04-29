#include <stdio.h>

//Máximo
int main() {
    int numeros[] = {23, 4, 5, 67, 71, 234, 59};
    int max = numeros[0];
    for (int i = 1; i < sizeof(numeros) / sizeof(int); i++) {
        if (numeros[i] > max) {
            max = numeros[i];
        }
    }
    printf("Máximo: %d \n", max);

    return 0;
}