#include <stdio.h>
#include <conio.h>

int main() {
    int lista [9]= {0,4,78,5,32,9,77,1,23};
    int i;

    for (i=0; i<9; i++){
        printf("digito %d: %d \n", i, lista[i]);
    }
    getch();
    return 0;
}