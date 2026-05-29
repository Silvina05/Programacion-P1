#include <stdio.h>

int ya_existe(int usados[], int cantidad, int num) {
    for (int i = 0; i < cantidad; i++) {
        if (usados[i] == num) return 1;
    }
    return 0;
}

void pedir_numero(int matriz[3][3], int i, int j, int usados[], int cantidad) {
    int num;
    printf("Ingrese numero para [%d][%d]: ", i, j);
    scanf("%d", &num);

    if (ya_existe(usados, cantidad, num)) {
        printf("  El numero %d ya existe. Ingrese otro.\n", num);
        pedir_numero(matriz, i, j, usados, cantidad); // recursion
    } else {
        matriz[i][j] = num;
        usados[cantidad] = num; // lo registramos en el array de usados
    }
}

int main() {
    int matriz[3][3];
    int min = 9999;
    int max = -9999;
    int array1[3];
    int fila_min = 0, col_min = 0;
    int fila_max = 0, col_max = 0;
    int usados[9]; // maximo 9 numeros en una matriz 3x3
    int cantidad = 0;

    // 1. Carga de datos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pedir_numero(matriz, i, j, usados, cantidad);
            cantidad++; // un numero mas fue aceptado
        }
    }

    // 2. Mostrar la matriz
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // 3. Buscar min, max y sus posiciones
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] < min) {
                min = matriz[i][j];
                fila_min = i;
                col_min = j;
            }
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                fila_max = i;
                col_max = j;
            }
        }
    }

    // 4. Resultados
    printf("\nEl valor MAYOR es %d y esta en la posicion [%d][%d]\n", max, fila_max, col_max);
    printf("El valor MENOR es %d y esta en la posicion [%d][%d]\n", min, fila_min, col_min);

    // 5. Diagonal principal
    printf("\nDiagonal principal: ");
    for (int i = 0; i < 3; i++) {
        array1[i] = matriz[i][i];
    }
    for (int i = 0; i < 3; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    return 0;
}