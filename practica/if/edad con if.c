#include <stdio.h>

int main() {
    int dia, mes, anio;
    int edad;

    // Fecha actual (podés cambiarla si querés)
    int dia_actual = 14;
    int mes_actual = 4;
    int anio_actual = 2026;

    printf("Ingrese su dia de nacimiento: ");
    scanf("%d", &dia);

    printf("Ingrese su mes de nacimiento: ");
    scanf("%d", &mes);

    printf("Ingrese su anio de nacimiento: ");
    scanf("%d", &anio);

    edad = anio_actual - anio;

    // Verificamos si ya cumplió años este año
    if (mes > mes_actual) {
        edad--; // aún no cumplió
    } else if (mes == mes_actual && dia > dia_actual) {
        edad--; // aún no cumplió
    }

    printf("Su edad es: %d\n", edad);

    return 0;
}