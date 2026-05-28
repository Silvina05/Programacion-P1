#include <stdio.h>

int main() {
    float array1[3];
    float array2[3];
    float array3[3]={0};
   
    for (int i = 0; i<3; i++){
        printf("ingrese numero para el primer arrayz\n");
        scanf("%f", &array1[i]);
        printf("ingrese numero para el segundo arrayz\n");
        scanf("%f", &array2[i]);

        if(array1 [i] != 0 && array2[i] !=0){
            array3[i]= array1[i]/array2[i];
           
        }
       else  printf("no coloque 0\n");

       
    }
     printf("resultados de la division \n");

    for (int i = 0; i < 3; i++) {
     printf("%.2f \n", array3[i]);
}

    

    return 0;
}