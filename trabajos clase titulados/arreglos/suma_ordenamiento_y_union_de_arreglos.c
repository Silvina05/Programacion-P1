#include <stdio.h>


int buscar(int lista[], int num);
void ordenar(int lista[]);

int main() {
    int A[10] = {10, 3, 30, 4, 5, 2, 7, 1, 9, 70};
    int B[10];
    int C[10];
    int i = 0, j = 0, aux = 0, n = 10;
    int D[20]; // máximo posible (A + B)
    int sizeD = 0; // Contador de elementos reales en D
    int b, centro;
    int inicio, fin, encontrado;

    // Entrada de datos para B
    for (int i = 0; i < 10; i++) {
        printf("Ingrese numero %d: ", i + 1);
        scanf("%d", &B[i]); 
    }

    // Mostrar matrices originales
    printf("\nNumeros ingresados matriz A:\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", A[i]);
    }
    printf("\nNumeros ingresados matriz B:\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", B[i]);
    }
    printf("\n");

    // Suma de A y B en C
    printf("\nContenido del arreglo C (Suma de A + B):\n");
    for (int i = 0; i < 10; i++) {
        C[i] = A[i] + B[i];
        printf("C[%d] = %d\n", i, C[i]);
    }

    // Ordenamiento Bubble Sort (Descendente)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (A[j] < A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
            if (B[j] < B[j + 1]) {
                aux = B[j];
                B[j] = B[j + 1];
                B[j + 1] = aux;
            }
        }
    }

    printf("\nNumeros ordenados matriz A (Descendente):\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", A[i]);
    }
    printf("\nNumeros ordenados matriz B (Descendente):\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", B[i]);
    }
    printf("\n");

    // Elementos repetidos - Unión en D
    // PASO 1: Meter elementos de A en D
    for (int i = 0; i < 10; i++) {
        int repetido = 0;
        for (int k = 0; k < sizeD; k++) {
            if (A[i] == D[k]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            D[sizeD] = A[i];
            sizeD++;
        }
    }

    // PASO 2: Meter elementos de B en D 
    for (int i = 0; i < 10; i++) {
        int repetido = 0;
        for (int k = 0; k < sizeD; k++) {
            if (B[i] == D[k]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            D[sizeD] = B[i];
            sizeD++;
        }
    }

    // Mostrar D
    printf("\nMatriz D (Union de A y B sin repetidos):\n");
    for (int i = 0; i < sizeD; i++) {
        printf(" %d ", D[i]);
    }
    printf("\n");

    // Búsqueda binaria en D
    // Nota: Para que la búsqueda binaria funcione, D DEBE estar ordenado.
    // Como A y B se ordenaron descendente, D suele quedar casi ordenado descendente.
    
    printf("\nIngrese elemento a buscar en D: ");
    scanf("%d", &b);

    inicio = 0;
    fin = sizeD - 1;
    encontrado = -1;

    while (inicio <= fin) {
        centro = (inicio + fin) / 2;

        if (D[centro] == b) {
            encontrado = centro;
            break;
        } 
        // Lógica para arreglo ordenado de mayor a menor
        else if (D[centro] < b) { 
            fin = centro - 1;
        } 
        else {
            inicio = centro + 1;
        }
    }

    if (encontrado != -1) {
        printf("Elemento %d encontrado en la posicion %d del arreglo D\n", b, encontrado);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}