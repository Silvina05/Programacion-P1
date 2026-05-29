#include <stdio.h>
#define max 3

void cargarmatriz(int matriz[][max], int n);
void pasararray(int matriz[][max], int array[]);
void verificar(int array[]);
void ordenar(int array[]); 
void buscar(int array[]);

int main() {
    int matriz[max][max];
    int array[max*max];
    int n = (max*max);

    
    // Llamadas a los procedimientos
    cargarmatriz(matriz, n); 
    pasararray(matriz, array);
    verificar(array);
    ordenar(array);
    buscar(array);

    return 0;
}

// Cargar matriz
void cargarmatriz(int matriz[][max], int n) {
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            printf("ingrese numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz:\n");
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Pasar de matriz a array 
void pasararray(int matriz[][max], int array[]) {
    int k = 0; 
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            array[k] = matriz[i][j];
            k++; 
        }
    }
}

// Verificar si es capicúa
void verificar(int array[]) {
    int esCapicua = 1;  
    int inicio = 0;
    int fin = (max*max) - 1;

    while (inicio < fin) {
        if (array[inicio] != array[fin]) {
            esCapicua = 0;  
            break;
        }
        inicio++;
        fin--;
    }
    
    if (esCapicua) {
        printf("Es capicua\n");
    } else {
        printf("No es capicua\n");
    }
}

// Ordenar por método burbuja (Menor a Mayor)
void ordenar(int array[]) {
    int i = 0;
    int j = 0;
    int temp; 
    int n = (max*max);
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j+1]) { //menor a mayor 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Buscar elemento (Búsqueda binaria)
void buscar(int array[]) {
    int buscado;
    int inicio = 0;
    int fin = (max*max) - 1;

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &buscado);

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (array[medio] == buscado) {
            printf("si esta en el array\n"); 
            break;
        }

        if (array[medio] < buscado) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    } 
    
    if (inicio > fin) {
        printf("No esta en el array\n");
    }
}
