#include <stdio.h>

int main() {
    int lanzamientos, resultado;
    int caras = 0, secas = 0;
    int contador = 1;
    float prob_cara, prob_seca;

    printf("¿Cuántas veces desea tirar la moneda? ");
    scanf("%d", &lanzamientos);

    while (contador <= lanzamientos) {
        printf("Tiro %d (1=Cara, 0=Seca): ", contador);
        scanf("%d", &resultado);

        if (resultado == 1) {
            caras++;
            contador++;
        } else if (resultado == 0) {
            secas++;
            contador++;
        } else {
            printf("Entrada no válida. Use 1 o 0.\n");
        }
    }

    if (lanzamientos > 0) {
        prob_cara = (float)caras / lanzamientos;
        prob_seca = (float)secas / lanzamientos;
        
        printf("\nprobabilidad de cada una\n");
        printf("Probabilidad de cara: %.2f\n", prob_cara*100);
        printf("Probabilidad de secas: %.2f\n", prob_seca*100);
    }

    return 0;
}


