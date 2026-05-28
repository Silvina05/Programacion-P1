#include <stdio.h>

int main() {
    int array[5]= {11,7,20,5,4};
    int num;
    int encontrado;

    encontrado=0;

    printf ("ingrese un numero para saber si esta en el array\n");
    scanf("%d", &num);
  
    for (int i = 0; i<5; i++){

        if (num == array[i]){
            encontrado=1;
        } 
    }

     if (encontrado == 1){
      printf("el numero si esta en el array\n");
        
        } else printf ("no esta en el array\n");
   


    return 0;
}