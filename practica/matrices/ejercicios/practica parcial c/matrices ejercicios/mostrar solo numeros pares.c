#include <stdio.h>

int main() {
    int matriz[2][2];
 

    
   
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
        printf("ingrese numero para la primera matriz \n");
        scanf("%d", &matriz[i][j]);
    }
    
  }

   for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
            if (matriz[i][j] % 2 == 0){
         printf("%d",matriz[i][j]);

            }
       
 }
 }


    

   

    

    return 0;
}