#include <stdio.h>
#include <conio.h>

int main() {
    int lista [10]= {0,4,79,5,32,9,77,1,23};
    int lista2 [10]= {0,4,78,5,32,9,77,1,23};
    int acum1=0;
    int acum2=0;

    //primer arreglo
    for (int i=0; i<10; i++){
           acum1=acum1+lista[i]; 
    }
    //segundo arreglo
     for (int i=0; i<10; i++){
           acum2=acum2+lista2[i]; 
    }
    // comparar
    if (acum1>acum2){
        printf ("el arreglo mayor es el primero con: %d\n", acum1);
    } else if (acum2>acum1) {
        printf ("el arreglo mayor es el segundo con: %d\n", acum2);
    } else printf ("son iguales \n");
    getch();
    return 0;
}