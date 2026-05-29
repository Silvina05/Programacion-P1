#include <stdio.h>
#include <conio.h>

int main() {
    int lista [9]= {0,4,78,5,32,9,77,1,23};
    int i;
    int acum=0;
    float prom;

    for (i=0; i<9; i++){
           acum=acum+lista[i]; 
    }
    prom= acum/9;
    printf("el promedio es %.2f \n", prom);
    getch();
    return 0;
}