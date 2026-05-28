#include <stdio.h>

int main() {
    int a[3], b[3];

    for(int i = 0; i < 3; i++) {
        printf("ingrese numero para el primer array ");
        scanf("%d", &a[i]);
        printf("ingrese numero para el segundo array ");
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < 3; i++) {
        printf("Suma: %d\n", a[i] + b[i]);
        printf("Resta: %d\n", a[i] - b[i]);
        printf("Multiplicacion: %d\n", a[i] * b[i]);

        if(b[i] != 0)
            printf("Division: %d\n", a[i] / b[i]);
    }

    return 0;
}