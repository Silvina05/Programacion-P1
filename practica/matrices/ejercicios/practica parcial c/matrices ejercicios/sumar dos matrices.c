#include <stdio.h>

int main() {
    int matriz1[2][2];
    int matriz2[2][2];
    int suma[2][2];
   
 
   // pedir la primer matriz
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la matriz \n");
        scanf("%d", &matriz1[i][j]);
    }
 }

 // pedir la segunda matriz
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la segunda matriz \n");
        scanf("%d", &matriz2[i][j]);
    }
    
  }



 //mostrar primer matriz
   for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf("%d ", matriz1[i][j]);
        } 
        printf("\n");

            }



//mostrar segunda matriz
     for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf("%d ", matriz2[i][j]);
        } 
        printf("\n");

            }
// calcular suma
     for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         suma[i][j]= matriz1[i][j]+matriz2[i][j];
        } 
        printf("\n");
    }
            


//mostrar suma
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf(" %d ", suma[i][j]);
        } 
        printf("\n");
    }

    return 0;
}