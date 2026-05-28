#include <stdio.h>

int main() {
    int array[5]= {10,79,20,5,4};
    int mayor;
    mayor=0;
    for (int i = 0; i<5; i++){
        if (array[i]> 10){
        mayor++;
        
        }
    }
    printf("cantidad de numeros mayores a 10 es  %d",mayor);
   


    return 0;
}