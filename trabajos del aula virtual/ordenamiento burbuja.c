#include <stdio.h>
#define  n 8

int main()
{
    int t, a[]={10, 8, 5, 3, 3, 2, 2, 1};
    int i, j, ninterc = 0;
    
    // El ordenamiento burbuja clásico va de 0 hasta n-1
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            // Compara el elemento actual con el Siguiente de forma segura
            if (a[j] > a[j+1]) /* Cambié < por > para que realmente sea ascendente */
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                ninterc++; /* Contador de intercambios */
            }
        }
    }
    
    // Mostrar el resultado
    for(i = 0; i < n; i++)
        printf("Posicion %d: %d \n", i, a[i]);
        
    printf("Numero de intercambios = %d \n", ninterc);
    return 0;
}
