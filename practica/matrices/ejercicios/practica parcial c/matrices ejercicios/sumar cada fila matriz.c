#include <stdio.h>

int main() {
    int matriz[2][2];
    int suma;
    
   
 
   
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la matriz \n");
        scanf("%d", &matriz[i][j]);
    }
    
  }

   for (int i = 0; i<2; i++){
        suma=0;
        for (int j = 0; j<2; j++){
        suma = suma +matriz[i][j];

            }
        printf("la suma es  %d ", suma);

       }
 

    

   

    

    return 0;
}