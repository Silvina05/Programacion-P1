#include <stdio.h>
#include <conio.h>

int main() {
    int lista [9]= {0,4,78,5,32,9,77,1,23};
    int i;
    int cont=0;

    for (i=0; i<9; i++){
        if (lista[i] % 2 == 0){
           cont++; 
        } 
    }
    printf("cantidad de numeros pares %d \n", cont);
    getch();
    return 0;
}