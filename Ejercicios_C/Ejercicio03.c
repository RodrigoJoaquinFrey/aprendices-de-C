#include <stdio.h>

//Mínimo
int main() {
    int numeros[] = {23, 4, 5, 67, 71, 234, 59};
    int min = numeros[0];
    for (int i = 1; i < sizeof(numeros) / sizeof(int); i++) {
        if (numeros[i] < min) {
            min = numeros[i];
        }
    }
    printf("Mínimo: %d \n", min);

    return 0;
}