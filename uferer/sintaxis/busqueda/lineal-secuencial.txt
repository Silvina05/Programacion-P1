#include <stdio.h>

int main() {
    int numeros[] = {10, 5, 8, 2, 7};
    int n = 5;
    int buscado = 8;
    int posicion = -1; // Usamos -1 para indicar "no encontrado"

    for (int i = 0; i < n; i++) {
        if (numeros[i] == buscado) {
            posicion = i; // ¡Lo encontramos!
            break; // No hace falta seguir buscando
        }
    }

    if (posicion != -1) {
        printf("Elemento encontrado en la posicion %d\n", posicion);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}