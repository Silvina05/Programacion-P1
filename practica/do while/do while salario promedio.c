#include <stdio.h>

int main() {
    float pago;
    float pp;
    float acum = 0; 

    printf("Ingrese primer pago: ");
    
    scanf("%f", &pp); 
    
    acum = pp;
    
    if (pp != 0) {
        do {
            printf("Ingrese siguiente pago (0 para terminar): ");
            scanf("%f", &pago);
            acum = acum + pago;
            
        } while (pago != 0);
    }


    printf("\nTotal del pago del mes: %.2f", acum);
    printf("\nGRACIAS POR USAR\n");
    
    return 0;
}