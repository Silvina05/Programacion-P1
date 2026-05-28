#include <stdio.h>

int main() {
    int matriz[2][2];
    int suma;
    
   
 
   
    for (int j = 0; j<2; j++){
        for (int i = 0; i<2; i++){
        printf("ingrese numero para la matriz \n");
        scanf("%d", &matriz[j][i]);
    }
    
  }

   for (int j = 0; j<2; j++){
        suma=0;
        for (int i = 0; i<2; i++){
        suma = suma +matriz[j][i];

            }
        printf("la suma es  %d ", suma);

       }
 

    

   

    

    return 0;
}