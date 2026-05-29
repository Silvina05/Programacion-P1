#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int nuevo_vector[10]; 
    int i;

    
    srand(time(NULL));

    
    for (i = 0; i < 10; i++) {
        nuevo_vector[i] = (rand() % 10) + 1;
    }

    
    printf("Los numeros aleatorios generados son:\n");
    for (i = 0; i < 10; i++) {
        printf("Posicion %d: %d\n", i, nuevo_vector[i]);
    }

     printf("\n");
      printf("en el siguiente texto se mostrara el vector, elevado al cuadrado y al cubo \n");

    for (i = 0; i < 10; i++) {
        
        double alCuadrado = pow((double)nuevo_vector[i], 2);
        double alCubo = pow((double)nuevo_vector[i], 3);

        printf("%-10d | %-10.0f | %-10.0f\n", nuevo_vector[i], alCuadrado, alCubo);
    }


    return 0;
}