#include <stdio.h>

int main() {
    int numeros[5], mayor;

    for(int i = 0; i < 5; i++) {
        printf("ingrese numero");
        scanf("%d", &numeros[i]);
    }

    mayor = numeros[0];

    for(int i = 1; i < 5; i++) {
        if(numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    printf("Mayor: %d", mayor);

    return 0;
}