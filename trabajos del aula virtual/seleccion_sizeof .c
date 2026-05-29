#include <stdio.h>

int main() {
    int arr[] = {7, 4, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);//calcula cuantos elementos tiene el array 
    //sizeof(arr): Mide el tamaño de todo el array. 
    //Como tenés 5 números enteros y cada uno ocupa 4 bytes, esto da un total de 20 bytes 
    //sizeof(arr[0]): Mide el tamaño de un solo elemento del array (el primero, que es un int). Eso da 4 bytes.
    //La división (20 / 4): Al dividir el total de bytes por lo que ocupa un solo número, el resultado de n es 5.
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Intercambio
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Arreglo ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
