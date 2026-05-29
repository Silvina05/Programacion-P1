#include <stdio.h>
#include <stdbool.h>

// 1. Declarar la dimensión del arreglo usando DEFINE
#define TAMANIO 10

// Prototipos de funciones y procedimientos
void cargarArreglo(int arr[], int n);
void mostrarArreglo(int arr[], int n);
void mostrarInverso(int arr[], int n);
bool esPrimo(int num);
int contarPrimos(int arr[], int n);
int contarOcurrencias(int arr[], int n, int valor);

int main() {
    int miArreglo[TAMANIO];
    int buscado, cantidad;

    // Ejecución de las consignas
    cargarArreglo(miArreglo, TAMANIO);
    
    printf("\nElementos del arreglo:\n");
    mostrarArreglo(miArreglo, TAMANIO);

    printf("\nCantidad de numeros primos: %d\n", contarPrimos(miArreglo, TAMANIO));

    printf("\nArreglo en sentido inverso:\n");
    mostrarInverso(miArreglo, TAMANIO);

    printf("\nIngrese un entero para buscar sus ocurrencias: ");
    scanf("%d", &buscado);
    printf("El numero %d aparece %d veces.\n", buscado, contarOcurrencias(miArreglo, TAMANIO, buscado));

    return 0;
}

// Cargar arreglo usando estructura repetitiva
void cargarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Ingrese el elemento [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Procedimiento para mostrar elementos
void mostrarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para determinar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Función para calcular la cantidad de números primos
int contarPrimos(int arr[], int n) {
    int contador = 0;
    for(int i = 0; i < n; i++) {
        if(esPrimo(arr[i])) {
            contador++;
        }
    }
    return contador;
}

// Procedimiento para mostrar en sentido inverso
void mostrarInverso(int arr[], int n) {
    for(int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para contar cuántas veces aparece un número
int contarOcurrencias(int arr[], int n, int valor) {
    int contador = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == valor) {
            contador++;
        }
    }
    return contador;
}