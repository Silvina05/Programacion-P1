#include <stdio.h>

int buscarBinarioDescendente(int lista[], int n, int num);
void ordenarBurbujaDescendente(int lista[], int n);

int main() {
    int A[10] = {10, 3, 30, 4, 5, 2, 7, 1, 9, 70};
    int B[10];
    int C[10];
    int D[20]; 
    int sizeD = 0;
    int b, n = 10;
    int posicion;

    // Entrada de datos para B
    for (int i = 0; i < 10; i++) {
        printf("Ingrese numero para B %d: ", i + 1);
        scanf("%d", &B[i]); 
    }

    // Suma de A y B en C
    printf("\nContenido del arreglo C (Suma de A + B):\n");
    for (int i = 0; i < 10; i++) {
        C[i] = A[i] + B[i];
        printf("%d ", C[i]);
    }
    printf("\n");

    // Ordenar A y B individualmente (Descendente)
    ordenarBurbujaDescendente(A, n);
    ordenarBurbujaDescendente(B, n);

    printf("\nMatriz A ordenada (Descendente): ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    
    printf("\nMatriz B ordenada (Descendente): ");
    for (int i = 0; i < n; i++) printf("%d ", B[i]);
    printf("\n");

    // Elementos únicos - Unión en D
    // Insertar de A
    for (int i = 0; i < 10; i++) {
        int repetido = 0;
        for (int k = 0; k < sizeD; k++) {
            if (A[i] == D[k]) { repetido = 1; break; }
        }
        if (!repetido) D[sizeD++] = A[i];
    }
    // Insertar de B
    for (int i = 0; i < 10; i++) {
        int repetido = 0;
        for (int k = 0; k < sizeD; k++) {
            if (B[i] == D[k]) { repetido = 1; break; }
        }
        if (!repetido) D[sizeD++] = B[i];
    }
// ordenar D
    ordenarBurbujaDescendente(D, sizeD);

    printf("\nMatriz D (Union ordenada descendente sin repetidos):\n");
    for (int i = 0; i < sizeD; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");

    // Búsqueda binaria en D
    printf("\nIngrese elemento a buscar en D: ");
    scanf("%d", &b);

    posicion = buscarBinarioDescendente(D, sizeD, b);

    if (posicion != -1) {
        printf("Elemento %d encontrado en la posicion (indice) %d del arreglo D\n", b, posicion);
    } else {
        printf("Elemento no encontrado en D\n");
    }

    return 0;
}


void ordenarBurbujaDescendente(int lista[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (lista[j] < lista[j + 1]) { // Signo < para descendente
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

// Implementación: Búsqueda Binaria para arreglos descendentes
int buscarBinarioDescendente(int lista[], int n, int num) {
    int inicio = 0;
    int fin = n - 1;
    int centro;

    while (inicio <= fin) {
        centro = (inicio + fin) / 2;

        if (lista[centro] == num) {
            return centro; // Encontrado
        } 
        // Si el número es mayor al centro, está a la izquierda (en descendente)
        else if (lista[centro] < num) { 
            fin = centro - 1;
        } 
        else {
            inicio = centro + 1;
        }
    }
    return -1; 
}