#include <stdio.h>

int main() {
    int matriz[2][2];
    int fila;
    int columna;
    int nuevo;
  
 
   //pido valores
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la primera matriz \n");
        scanf("%d", &matriz[i][j]);
    }
    
  }
  printf("ingrese la fila que desea editar ");
  scanf("%d", &fila);
  printf("ingrese la columna que desea editar ");
  scanf("%d", &columna);
  printf("ingrese nuevo valor ");
  scanf("%d", &nuevo);
  matriz[fila][columna] = nuevo;
 


//muestro
   for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf ("%d", matriz[i][j]);

       }
       printf("\n");
 }


    

   

    

    return 0;
}