#include <stdio.h>

int main() {
    int matriz[3][3];
    int array [9];
    int k=0;
    int i=0;
    int n=9;
    int aux=0;
    int j=0;
// ingresar matriz 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("ingrese numero ");
            scanf("%d", &matriz[i][j]);
        }
    }

// convertir en array
    k = 0; 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            array[k] = matriz[i][j];
            k++; 
        }
    }

// ordenamiento
     for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
               
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
// vover a matriz
        k = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matriz[i][j] = array[k];
            k++;
        }
    }

//mostrar
     for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}