#include <stdio.h>

int main() {
    int matriz[2][2];
    int num;
    int existe=0;
   
 
   
    for (int j = 0; j<2; j++){
        for (int i = 0; i<2; i++){
        printf("ingrese numero para la matriz \n");
        scanf("%d", &matriz[j][i]);
    }
    
  }
  printf("ingrese el numero que quiera buscar\n");
    scanf("%d", &num);

   for (int j = 0; j<2; j++){
        
        for (int i = 0; i<2; i++){
        if (num== matriz[j][i]){
            existe=1;

        } 

            }
       

       }
       if (existe==1){
    printf("el numero %d si existe en la matriz", num);

       } else printf("el numero %d no existe en la matriz", num);

   
    

   

    

    return 0;
}