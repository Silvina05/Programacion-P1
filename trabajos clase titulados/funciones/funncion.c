#include <stdio.h>
#define max 5

// Prototypes
void mostrar(int a[]);
int pares(int a[]);

int main() {
    int vec[max], p;
    int i;

    for (i = 0; i < max; i++) {
        printf("Ingrese un numero entero\n");
        scanf("%d", &vec[i]);
    }

    mostrar(vec);      // Prints the array
    p = pares(vec);    // Counts the even numbers
    printf("La cantidad de elementos pares es: %d \n", p);

    return 0;
}

// Function to just display the elements
void mostrar(int a[]) {
    int i;
    printf("Elementos del vector: ");
    for (i = 0; i < max; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to count even numbers
int pares(int a[]) {
    int i, cant = 0;
    for (i = 0; i < max; i++) {
        if (a[i] % 2 == 0) {
            cant++;
        }
    }
    return cant;
}