#include <stdio.h>

int main() {
int nota;
int legajos;
int ca = 0;
int cr=0;
int cp=0;

 do {
 printf ("ingrese el legajo (negativo para salir)  \n");
 scanf ("%d", &legajos);
 if (legajos>=0){
 printf ("ingrese la nota del alumno\n");
 scanf ("%d", &nota);
 if (nota > 5 && nota < 8) {
    printf ( "A   legajo: %d\n", legajos);
    ca++;
 }
 else if (nota <= 5){
    printf ("R  legajo:  %d\n", legajos);
    cr++;
 }
 else if (nota >= 8){
    printf ("P  legajo: %d\n", legajos);
    cp++;
 }
 }
 }while (legajos >= 0);
 printf ("Aprobados %d\n", ca);
 printf ("reprobados %d\n", cr);
 printf ("promocionados %d\n", cp);

 return 0;
}