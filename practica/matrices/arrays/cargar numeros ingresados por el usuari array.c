#include <stdio.h>

int main() {
    int numeros[5];

    // Cargar
    for(int i = 0; i < 5; i++) {
        printf("Ingrese numero: ");
        scanf("%d", &numeros[i]);
    }

    // Mostrar
    printf("Array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}