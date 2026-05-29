#include <stdio.h> 
#include <conio.h>
int main()
{
char cadena[5];
 for(int i = 0; i < 5; i++) {
        printf("Ingrese letra: ");
        scanf(" %c", &cadena[i]);
    }

    // Mostrar
    printf("Array: ");
    for(int i = 0; i < 5; i++) {
        printf(" %c ", cadena[i]);
    }
getch();
return 0;
}
