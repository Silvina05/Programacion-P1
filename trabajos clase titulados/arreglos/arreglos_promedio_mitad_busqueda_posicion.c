#include <stdio.h>
#include <conio.h>

int main() {
    int lista[10] = {0, 3, 4, 78, 5, 32, 9, 77, 1, 23};
    int i;
    int acum = 0; // IMPORTANTE: Inicializar en 0 para que no sume basura
    float prom = 0;
    float mitadpromedio = 0;
    int posicion=0;
    int elegido=0;
    int esta=0;

    // Mostrar y acumular
    for (i = 0; i < 10; i++) {
        printf("%d", lista[i]);
        if (i < 9) printf("--"); // Estético: evita el -- al final
        acum = acum + lista[i];
    }

    printf("\n");
    prom = (float)acum / 10;
    printf("El promedio es %.2f \n", prom);

    // CORRECCIÓN: Quitamos el "float" de adelante porque ya estaba declarada arriba
    mitadpromedio = prom / 2; 
    
    printf("\nElementos mayores a la mitad del promedio (%.2f): ", mitadpromedio);
    for (i = 0; i < 10; i++) { // Usamos la 'i' que ya declaraste arriba
        if (lista[i] > mitadpromedio) {
            printf("%d ", lista[i]);
        }
    }
    printf("\n");

    printf ("ingrese una posicion para buscar en la matriz\n");
    scanf("%d", &posicion);
     if (posicion >= 0 && posicion <=10 ){
        printf ("en la posicion %d se encuentra el numero %d", posicion, lista[posicion]);
     }

     printf("\n");

     printf ("ingrese un numero para buscar en la matriz\n");
    scanf("%d", &elegido);
     for (i = 0; i < 10; i++) { 
        if (lista[i] == elegido) {
            esta=1;
            break;
        }
        
    }
    if (esta == 1){
        printf("el numero %d esta en la matriz", elegido);
    } else printf ("el numero %d no esta en la matriz", elegido);
     



    

    return 0;
}