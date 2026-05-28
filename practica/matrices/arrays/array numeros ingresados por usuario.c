#include <stdio.h>

int main() {
    int numeros[5];

  
    for(int i = 0; i < 5; i++) {
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Numeros ingresados:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}