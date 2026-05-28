#include <stdio.h>

int main() {
    int lista[5] = {11, 7, 20, 5, 4};
    int aux; // Este es nuestro "vaso vacío" para el intercambio

    // El primer bucle asegura que repitamos el proceso suficientes veces
    for (int i = 0; i < 5; i++) {
        
        // El segundo bucle recorre el array comparando parejas
        // Usamos "4" porque comparamos j con j+1 (si llegamos a 5, j+1 se sale del array)
        for (int j = 0; j < 4; j++) {
            
            // Si el número de la izquierda es mayor al de la derecha...
            if (lista[j] > lista[j+1]) {
                
                // ¡INTERCAMBIO! (Lógica del tercer vaso)
                aux = lista[j];          // Guardamos el grande en aux
                lista[j] = lista[j+1];   // Pasamos el chico a la izquierda
                lista[j+1] = aux;        // Pasamos el grande (desde aux) a la derecha
            }
        }
    }

    // Mostramos el resultado final
    printf("Array ordenado de menor a mayor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}