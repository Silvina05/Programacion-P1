#include <stdio.h>

int main() {
    int num;
    int suma=0;
    printf ("ingrese un numero\n");
    scanf("%d", &num);
for (int i=1; i< num; i++){
   if (num % i == 0){
    suma=suma+i;
   }
 }
 if (suma == num){
    printf("el numero es perfecto");
  } else printf ("no es un numero perfecto");
 

    return 0;
}