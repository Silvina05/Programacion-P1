#include <stdio.h>

int main() {
    int array1[3];
    int num;
    int remplazo;
    
   
    for (int i = 0; i<3; i++){
        printf("ingrese numero para el array \n");
        scanf("%d", &array1[i]);

    }

     printf("ingese el numero que desea editar \n");
     scanf("%d", &num);
     printf("ingese el numero a reemplazar \n");
     scanf("%d", &remplazo);

     for (int i = 0; i<3; i++){
     if(num==array1[i]){
        array1[i]=remplazo;
     }
     }

     for (int i = 0; i<3; i++){
     printf("%d", array1[i]);

     }

   

    

    return 0;
}