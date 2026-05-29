#include <stdio.h>

// --- ESTA ES NUESTRA CALCULADORA (BÁSICA Y PASO A PASO) ---
int calcular_mcd(int fila, int columna) {
    int menor;

    // 1. Averiguamos cuál de los dos números es el más chico
    if (fila < columna) {
        menor = fila;
    } else {
        menor = columna;
    }

    // 2. Empezamos desde ese número menor y vamos bajando de 1 en 1.
    // El primer número que divida a la 'fila' y a la 'columna' al mismo tiempo, es el resultado.
    for (int i = menor; i >= 1; i--) {
        
        // El símbolo % busca el resto. Si el resto es 0, significa que lo divide perfecto.
        if (fila % i == 0 && columna % i == 0) {
            return i; // ¡Encontrado! Devolvemos el divisor máximo y la función termina.
        }
    }

    return 1; // Por seguridad, si no encuentra ninguno, el 1 siempre divide a todos.
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    // El conjunto de números que te dio el ejercicio
    int D50[6] = {1, 2, 5, 10, 25, 50};

    // 1. DIBUJAMOS EL ENCABEZADO DE ARRIBA (Las columnas)
    printf("m.c.d \t| ");
    for (int j = 0; j < 6; j++) {
        printf("%d\t| ", D50[j]);
    }
    printf("\n-------------------------------------------------------------\n");

    // 2. RECORREMOS LA TABLA PASO A PASO
    for (int i = 0; i < 6; i++) {
        
        // Guardamos el número de la fila actual en una variable con un nombre claro
        int numero_de_fila = D50[i]; 
        
        // Imprimimos ese número a la izquierda de todo antes de los resultados
        printf("%d\t| ", numero_de_fila);         

        // Ahora recorremos las columnas de este renglón
        for (int j = 0; j < 6; j++) {
            
            // Guardamos el número de la columna actual en otra variable clara
            int numero_de_columna = D50[j];

            // LLAMADA A LA FUNCIÓN:
            // Le enviamos "numero_de_fila" (va directo a la variable 'fila' de arriba)
            // Le enviamos "numero_de_columna" (va directo a la variable 'columna' de arriba)
            int resultado_mcd = calcular_mcd(numero_de_fila, numero_de_columna);

            // Imprimimos el resultado en la pantalla
            printf("%d\t| ", resultado_mcd);  
        }
        
        // Terminó la fila entera, saltamos de renglón abajo
        printf("\n");
    }

    return 0;
}