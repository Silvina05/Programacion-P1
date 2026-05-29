#include <stdio.h>
#include <conio.h>

int main() {
    int lista [10]= {0,4,78,5,32,9,77,1,23,12};
    int i;
    
    for (i=0; i<10; i++){
          printf("ingresar elemento %d \n", i );
          scanf("%d", &lista[i]);
    }
    // mostrar elementos del arreglo
    for (i=0; i<10; i++){
        printf("elemento %d: %d\n", i+1, lista[i]);
        if (lista[i]%2==0) printf("elemento par\n");
    }

    return 0;
    getch();
}