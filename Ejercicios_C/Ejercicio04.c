#include <stdio.h>

//Promedio
int main(){
    int promediables[3];
    int suma = 0;
    printf("Ingrese 3 números enteros: \n");
    scanf("%d %d %d", &promediables[0],&promediables[1],&promediables[2]);

    for (int i = 0; i < sizeof(promediables) / sizeof(int); i++) {
        suma = suma + promediables[i];
    }
    float promedio = (float) suma / sizeof(promediables) * sizeof(int);
    printf("Promedio: %f\n" , promedio);

    return 0;
}