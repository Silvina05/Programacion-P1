#include <stdio.h>

int main() {
    int numeros;
    printf ("ingrese un numero para saber si es par ");
    scanf ("%d", &numeros);
    if (numeros % 2 == 0){
        printf ("el numero es par");

    } else printf("el numero es impar");
   


    return 0;
}