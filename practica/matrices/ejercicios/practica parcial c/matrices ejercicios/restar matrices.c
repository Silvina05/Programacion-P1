#include <stdio.h>

int main() {
    int matriz1[2][2];
    int matriz2[2][2];
    int resta[2][2];
   
 
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


printf ("primer matriz\n");
 //mostrar primer matriz
   for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf("%d ", matriz1[i][j]);
        } 
        printf("\n");

            }


printf ("segunda matriz\n");
//mostrar segunda matriz
     for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf("%d ", matriz2[i][j]);
        } 
        printf("\n");

            }
//calcular resta
     for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         resta[i][j]= matriz1[i][j]-matriz2[i][j];
        } 
        printf("\n");
    }
            

printf ("resta matriz\n");
//mostrar resta
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
         printf(" %d ", resta[i][j]);
        } 
        printf("\n");
    }

    return 0;
}