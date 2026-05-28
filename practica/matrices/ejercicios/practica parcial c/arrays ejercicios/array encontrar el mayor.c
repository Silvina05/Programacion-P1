#include <stdio.h>

int main() {
    int array[5]= {10,7,20,5,4};
    int mayor;
    mayor=array[0];
    for (int i = 0; i<5; i++){
        if (array[i]> mayor){
        mayor= array[i];
        
        }
    }
    printf("el mayor es  %d ",mayor);
   


    return 0;
}