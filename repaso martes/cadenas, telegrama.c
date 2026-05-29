#include <stdio.h>
#include <string.h>

int main() {
    char telegrama[500];
    int oraciones = 0, palabras = 0, caracteres = 0;
    int i = 0;

    printf("Ingrese el telegrama (finalice con --): ");
    scanf("%s", telegrama);

    // Recorrer el telegrama hasta encontrar --
    while (telegrama[i] != '\0') {

        // Detectar fin del telegrama
        if (telegrama[i] == '-' && telegrama[i+1] == '-') {
            break;
        }

        if (telegrama[i] == '.') {
            oraciones++;         // Contar oraciones
            palabras++;          // El ultimo * de la oracion falta, lo compensamos

        } else if (telegrama[i] == '*') {
            palabras++;          // Contar separadores de palabras

        } else {
            caracteres++;        // Contar caracteres sin * ni .
        }

        i++;
    }

    // Calcular costo 
    int costo = 0;

    if (oraciones == 1 && palabras == 5) {
        costo = caracteres * 100;
    } else if (oraciones >= 2 && oraciones <= 3 && palabras <= 15) {
        costo = caracteres * 500;
    } else {
        costo = caracteres * 1000;
    }

    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    printf("Oraciones : %d\n", oraciones);
    printf("Palabras  : %d\n", palabras);
    printf("Caracteres: %d\n", caracteres);
    printf("Costo     : $%d\n", costo);

    return 0;
}