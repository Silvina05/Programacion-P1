#include <stdio.h>

int main() {
    int lista[8] = {1, 2, 3, 3, 5, 6, 77, 88}; // El arreglo DEBE estar ordenado
    int b, centro;
    int inicio = 0;
    int fin = 7; // El último índice (8 elementos -> 0 a 7)
    int encontrado = -1; // Guardaremos la posición aquí

    printf("Ingrese elemento a buscar con Busqueda Binaria: ");
    scanf("%d", &b);

    while (inicio <= fin) {
        centro = (inicio + fin) / 2; // Calculamos el punto medio

        if (lista[centro] == b) {
            encontrado = centro; // ¡Lo encontramos!
            break; // Salimos del bucle
        } 
        else if (lista[centro] > b) {
            // El número es más chico, descartamos la derecha
            fin = centro - 1;
        } 
        else {
            // El número es más grande, descartamos la izquierda
            inicio = centro + 1;
        }
    }

    if (encontrado != -1) {
        printf("Elemento %d encontrado en la posicion %d\n", b, encontrado);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}