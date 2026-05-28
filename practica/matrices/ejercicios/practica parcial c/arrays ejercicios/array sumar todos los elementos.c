#include <stdio.h>

int main() {
    int array[5]= {10,7,6,5,4};
    int suma;
    suma=0;
    for (int i = 0; i<5; i++){
        printf("%d ",array[i]);
        suma=suma+array[i];
    }
    printf("la suma es %d ", suma);


    return 0;
}