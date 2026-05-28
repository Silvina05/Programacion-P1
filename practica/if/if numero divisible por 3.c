#include <stdio.h>

int main() {
    int numero; 
    
    printf("Ingrese un numero para saber si es divisible por 3: ");
    scanf("%d", &numero);
    
    if (numero % 3 == 0) {
        printf("El numero %d es divisible por 3\n", numero);
    } else {
        printf("El numero %d NO es divisible por 3\n", numero);
    }

    return 0;
}