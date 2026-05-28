#include <stdio.h>

int main() {
    int matriz[2][2];
    int suma;
    suma=0;

    
   
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la primera matriz \n");
        scanf("%d", &matriz[i][j]);
    }
    
  }

   for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("%d",matriz[i][j]);
        suma=suma+matriz[i][j];
    }
    printf("\n");
 }
printf("la suma es %d ", suma);

    

   

    

    return 0;
}