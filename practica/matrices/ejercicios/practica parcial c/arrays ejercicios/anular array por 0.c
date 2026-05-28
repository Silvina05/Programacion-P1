#include <stdio.h>

int main() {
    int array1[3];
    int num;
    
   
    for (int i = 0; i<3; i++){
        printf("ingrese numero para el segundo array \n");
        scanf("%d", &array1[i]);

    }

     printf("ingese el valor que desea borrar \n");
     scanf("%d", &num);

     for (int i = 0; i<3; i++){
     if(num==array1[i]){
        array1[i]=0;
     }
     }

     for (int i = 0; i<3; i++){
     printf("%d", array1[i]);

     }

   

    

    return 0;
}