#include <stdio.h>

int main() {
    // Ambiente
    int lista[8]={1,2,3,3,5,6,77,88};
    int i, b, a;
    int enc = 0; // Importante inicializar el contador en 0

    // Algoritmo: Cargar el arreglo
    for (i = 0; i < 8; i++) {
        printf("Ingresar el elemento %d: ", i);
        scanf("%d", &a);
        lista[i] = a;
    }

    // Mostrar elementos y decir si son pares
    for (i = 0; i < 8; i++) {
        printf("%d ", lista[i]);
        if (lista[i] % 2 == 0) {
            printf("<- Es par");
        }
        printf("\n");
    }

    // Buscar elemento
    printf("\nIngrese elemento a buscar: ");
    scanf("%d", &b);

    i = 0;
    while (i < 10 && lista[i] >= b  ) {
        if (b == lista[i]) {
            enc = enc + 1; // Cuenta las ocurrencias
        }
        i = i + 1;
    }

    // Resultado final
    if (enc == 0) {
        printf("Elemento no encontrado\n");
    } else {
        printf("Elemento encontrado: %d veces\n", enc);
    }

    return 0;
}