#include <stdio.h>

int main()
{
 int nota, sumatoria=0, cantidad, contador=1;
 float promedio=0; 

 printf ("¿cuantas notas desea ingresar? ");
 scanf("%d", &cantidad);

 while (contador<= cantidad)
 {

    printf ("ingrese la nota %d: " , contador);
    scanf("%d", &nota);
    sumatoria += nota; 
    contador++;

 } 
 promedio =(float)sumatoria / cantidad;
 printf ("el promedio es: %.2f\n", promedio);

 return 0;

}
